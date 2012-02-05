<?php
/**
 * @file
 * sa_image_slideshow.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function sa_image_slideshow_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'image_slide';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Image slide';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_image_slideshow',
      'hide_title' => 1,
      'title' => 'View',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'panels_mini_delta_image_slideshow_reorder',
      'hide_title' => 1,
      'title' => 'Reorder/edit',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'path' => 'node/add/slideshow-image',
      'title' => 'Add',
      'weight' => '-98',
      'type' => 'callback',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Add');
  t('Image slide');
  t('Reorder/edit');
  t('View');

  $export['image_slide'] = $quicktabs;

  return $export;
}
