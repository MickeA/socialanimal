<?php

/**
 * @file
 * Styles class implementation for Media: SoundCloud.
 */

class MediaSoundCloudStyles extends FileStyles {
  public $autoplay;

  function getAutoplay() {
      //drupal_set_message("getAutoplay");
    return $this->get('autoplay');
  }
  function setAutoplay($value) {
      //drupal_set_message("setAutoplay");
    return $this->set('autoplay', $value);
  }

  function getImageUri() {
      //drupal_set_message("getImageUri");
    if ($image_uri = $this->get('imageUri')) {
      return $image_uri;
    }
    $object = $this->getObject();
    if ($object->uri) {
      $wrapper = file_stream_wrapper_get_instance_by_uri($object->uri);
      return $wrapper->getLocalThumbnailPath();
    }
  }
  function audio($effect) {
      //drupal_set_message("audio");
    $variables = array(
      'uri' => $this->getUri(),
      'width' => $this->getWidth(),
      'autoplay' => $this->getAutoplay(),
    );
    $this->setOutput(theme('media_soundcloud_audio', $variables));
  }
}
