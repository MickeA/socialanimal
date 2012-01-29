<?php

/**
 * @file media_soundcloud/includes/themes/media_soundcloud.theme.inc
 *
 * Theme and preprocess functions for Media: SoundCloud.
 */

/**
 * Preprocess function for theme('media_soundcloud_audio').
 */
function media_soundcloud_preprocess_media_soundcloud_audio(&$variables) {
  //drupal_set_message("media_soundcloud_preprocess_media_soundcloud_audio");  
  // Build the URL for display.
  $uri = $variables['uri'];
  $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
  $parts = $wrapper->get_parameters();
  //drupal_set_message(print_r($wrapper,true));
  $url = $wrapper->interpolateUrl();
  //drupal_set_message(print_r($url,true));
  $embed_data = $wrapper->getOEmbed($url);
  //drupal_set_message(print_r($embed_data,true));
  //drupal_set_message(print_r($embed_data,true));
  if(isset($parts['u'])){
    $variables['user_name'] = check_plain($parts['u']);
    $variables['wrapper_id'] = 'media_soundcloud_' . $variables['user_name'] . '_' . $variables['id'];
  }
  if(isset($parts['a'])){
    $variables['audio_name'] = check_plain($parts['a']);
    $variables['wrapper_id'] = 'media_soundcloud_' . $variables['audio_name'] . '_' . $variables['id'];
  }
  if(isset($parts['g'])){
    $variables['group_name'] = check_plain($parts['g']);
    $variables['wrapper_id'] = 'media_soundcloud_' . $variables['group_name'] . '_' . $variables['id'];
  }
  if(isset($parts['s'])){
    $variables['set_name'] = check_plain($parts['s']);
    $variables['wrapper_id'] = 'media_soundcloud_' . $variables['set_name'] . '_' . $variables['id'];
  }
  
  $variables['width'] = isset($variables['width']) ? $variables['width'] : media_soundcloud_variable_get('width');
  $variables['autoplay'] = isset($variables['autoplay']) ? $variables['autoplay'] : media_soundcloud_variable_get('autoplay');
  $variables['autoplay'] = $variables['autoplay'] ? 1 : 0;  

  $variables['output'] = str_replace('width="100%"', 'width="'.$variables['width'].'"', $embed_data['html']);
  //drupal_set_message(print_r($variables,true));
  
  // @todo Replace this inline JavaScript with at least calls to
  //   drupal_add_js()/drupal_get_js(), and ideally, with a behavior. Keep
  //   in mind that the solution needs to work when inside a colorbox or
  //   otherwise in an AJAX response, but that should now be possible in D7.
  $iframe_id = drupal_json_encode($variables['wrapper_id'] .'_iframe');
  $wrapper_id = drupal_json_encode($variables['wrapper_id']);
  $JSObject = 'Drupal.settings.media_soundcloud[' . $wrapper_id . ']';
  $variables['output'] .= <<<OUTPUT
    <script type="text/javascript">
      if (Drupal.settings && Drupal.media_soundcloud) {
        Drupal.settings.media_soundcloud = Drupal.settings.media_soundcloud || {};
        $JSObject = {};
        $JSObject.width = {$variables['width']};
        $JSObject.embed_url = "{$url}";
        $JSObject.id = $iframe_id;
        $JSObject.options = { autoplay: {$variables['autoplay']} };
        Drupal.media_soundcloud.insertEmbed($wrapper_id);
      }
    </script>
OUTPUT;
  drupal_add_js(drupal_get_path('module', 'media_soundcloud') . '/js/media_soundcloud.js');
  drupal_add_css(drupal_get_path('module', 'media_soundcloud') . '/css/media_soundcloud.css');
  drupal_add_js(drupal_get_path('module', 'media_soundcloud') . '/js/flash_detect_min.js'); 
}

function theme_media_soundcloud_field_formatter_styles($variables) {
  drupal_set_message("theme_media_soundcloud_field_formatter_styles");
  $element = $variables['element'];
  $style = $variables['style'];
  $variables['file'] = $element['#item'];
  $variables['uri'] = $variables['file']['uri'];
  $variables['style_name'] = $style['name'];
  return theme('media_soundcloud_embed', $variables);
}

/**
 * Preview for Styles UI.
 */
function theme_media_soundcloud_preview_style($variables) {
  //drupal_set_message("theme_media_soundcloud_preview_style");
  $variables['uri'] = media_soundcloud_variable_get('preview_uri');
  $variables['field_type'] = 'file';
  $variables['object'] = file_uri_to_object($variables['uri']);

  return theme('styles', $variables);
}

/**
 * NOTE: Deprecated with Styles version 2.
 */
function theme_media_soundcloud_styles($variables) {
  //drupal_set_message("theme_media_soundcloud_styles");
  $style = $variables['style'];
  $variables['file'] = $variables['object'];
  $variables['uri'] = $variables['object']->uri;
  $variables['style_name'] = $style['name'];
  return theme('media_soundcloud_embed', $variables);
}

/**
 * @todo: get this working
 *
 * This code is for embedding audios in WYSIYWG areas, not currently working.
 * NOTE: Deprecated with Styles version 2.
 */
function theme_media_soundcloud_embed($variables) {
  //drupal_set_message("theme_media_soundcloud_embed");
  $preset_name = $variables['preset_name'];
  $preset = styles_containers_available_styles('file', 'media_soundcloud', $preset_name);
  $output = '';
  if (!empty($preset)) {
    // Build the URL for display.
    $uri = $variables['uri'];
    $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
    $parts = $wrapper->get_parameters();

    $in_browser = $thumbnail = FALSE;

    foreach ($preset['effects'] as $effect) {
      switch ($effect['name']) {
        case 'autoplay':
          $autoplay = $effect['data']['autoplay'] ? 'true' : 'false';
          break;
        case 'resize':
          $width = $effect['data']['width'];
          break;
        case 'thumbnail':
          $thumbnail = $effect['data']['thumbnail'];
      }
    }
    if (isset($variables['object']->override)) {
      $override = $variables['object']->override;
      if (isset($override['width'])) {
        $width = $override['width'];
      }
      if (isset($override['wysiwyg'])) {
        $thumbnail = TRUE;
      }
      if (isset($override['browser']) && $override['browser']) {
        $in_browser = TRUE;
        $thumbnail = TRUE;
      }
    }
    $width = isset($width) ? $width : media_soundcloud_variable_get('width');
    $user_name = check_plain($parts['u']);
    $audio_name = check_plain($parts['a']);
    if ($thumbnail) {
      // @todo Clean this up.
      $image_variables = array(
        'path' => $wrapper->getOriginalThumbnailPath(),
        'alt' => $variables['alt'],
        'title' => $variables['title'],
        'getsize' => FALSE,
      );
      if (isset($preset['image_style'])) {
        $image_variables['path'] = $wrapper->getLocalThumbnailPath();
        $image_variables['style_name'] = $preset['image_style'];
        $output = theme('image_style', $image_variables);
      }
      else {
        // We need to add this style attribute here so that it doesn't get lost
        // If you resize a audio in a node, save it, edit it, but don't adjust
        // the sizing of the audio while editing, the size will revert to the
        // default.  Adding the specific size here retains the original resizing
        $WYSIWYG = isset($variables['object']->override['style']) ? $variables['object']->override['style'] : '';
        $image_variables['attributes'] = array('width' => $width, 'style' => $WYSIWYG);
        $output = theme('image', $image_variables);
      }
      if ($in_browser) {
        // Add an overlay that says 'SoundCloud' to media library browser thumbnails.
        $output .= '<span />';
      }
    }
    else {
      $output = theme('media_soundcloud_audio', array('uri' => $uri, 'width' => $width, 'autoplay' => ($autoplay == 'true' ? TRUE : NULL)));
    }
  }
  return $output;
}
