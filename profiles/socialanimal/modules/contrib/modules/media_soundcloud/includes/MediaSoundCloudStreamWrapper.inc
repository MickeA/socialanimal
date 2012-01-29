<?php

/**
 *  @file
 *  Create a SoundCloud Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $soundcloud = new ResourceSoundCloudStreamWrapper('soundcloud://u/[user-name]/a/[audio-code]');
 */
class MediaSoundCloudStreamWrapper extends MediaReadOnlyStreamWrapper {
  protected $base_url = 'http://soundcloud.com/'; 
  protected $parameters = array('u','a','g','s');
  
  function interpolateUrl() {
    $url = "";
    if(isset($this->parameters['u'])){
        $url = $this->base_url . check_plain($this->parameters['u']);   
    }
    //group set
    if(isset($this->parameters['g'])){
        $url = $this->base_url . 'groups/' . check_plain($this->parameters['g']);   
    }
    //single song
    if(isset($this->parameters['u']) && isset($this->parameters['a'])){
        $url = $this->base_url . check_plain($this->parameters['u']) . '/' . check_plain($this->parameters['a']);
    }
    //audio sets
    if(isset($this->parameters['u']) && isset($this->parameters['s'])){
        $url = $this->base_url . check_plain($this->parameters['u']) . '/sets/' . check_plain($this->parameters['s']);
    }
    return $url;
  }
  
  function getTarget($f) {
    return FALSE;
  }

  static function getMimeType($uri, $mapping = NULL) {
    return 'audio/soundcloud';
  }

  function getOriginalThumbnailPath() {
    //return a thumbnail image
    return drupal_get_path('module','media_soundcloud') . "/images/thumb_image.jpg";
  }

  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    $local_path = "";
    //user set
    if(isset($parts['u'])){
        $local_path = 'public://media-soundcloud/u/' . check_plain($parts['u']) . '.jpg';   
    }
    //group set
    if(isset($parts['g'])){
        $local_path = 'public://media-soundcloud/g/' . check_plain($parts['g']) . '.jpg';   
    }
    //single song
    if(isset($parts['u']) && isset($parts['a'])){
        $local_path = 'public://media-soundcloud/u/' . check_plain($parts['u']) . '/a/'.check_plain($parts['a']).'.jpg';
    }
    //audio sets
    if(isset($parts['u']) && isset($parts['s'])){
        $local_path = 'public://media-soundcloud/u/' . check_plain($parts['u']) . '/s/'.check_plain($parts['s']).'.jpg';
    }
    
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      @copy($this->getOriginalThumbnailPath(), $local_path);
    }
    return $local_path;
  }
  
  public function getOEmbed($url) {
    //drupal_set_message("MediaSoundCloudStreamWrapper::getOEmbed");
    $oembed_url = url('http://soundcloud.com/oembed', array('query' => array('url' => $url, 'format' => 'json')));
    //drupal_set_message(print_r($oembed_url,true));
    $response = drupal_http_request($oembed_url);
    //drupal_set_message(print_r($response,true)); 
    if (!isset($response->error)) {
      return drupal_json_decode($response->data);
    }else{
        drupal_set_message("Error Embeding SoundCloud Media code(".$response->code.") : " . $response->status_message);
        drupal_set_message('Please check sharing permissions');
        //drupal_set_message(print_r($response,true));
    }
  }
}
