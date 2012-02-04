<?php
/**
 * @file
 * sa_image_slideshow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sa_image_slideshow_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sa_image_slideshow_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function sa_image_slideshow_image_default_styles() {
  $styles = array();

  // Exported image style: slideshow_image
  $styles['slideshow_image'] = array(
    'name' => 'slideshow_image',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '941',
          'height' => '400',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function sa_image_slideshow_node_info() {
  $items = array(
    'slideshow_image' => array(
      'name' => t('Slideshow image'),
      'base' => 'node_content',
      'description' => t('Add a slideshow image'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
