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
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
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
      'vid' => 'image_slide',
      'display' => 'reorder_slideshow',
      'args' => '',
      'title' => 'Reorder/edit',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'bid' => 'panels_mini_delta_add_slideshow_image_form',
      'hide_title' => 1,
      'title' => 'Add',
      'weight' => '-98',
      'type' => 'block',
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
