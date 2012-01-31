<?php
/**
 * @file
 * sa_image_slideshow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sa_image_slideshow_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_slideshow_image';
  $strongarm->value = 0;
  $export['enable_revisions_page_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_slideshow_image';
  $strongarm->value = array();
  $export['menu_options_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_slideshow_image';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_slideshow_image';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_slideshow_image';
  $strongarm->value = '0';
  $export['node_preview_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_slideshow_image';
  $strongarm->value = 0;
  $export['node_submitted_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_slideshow_image';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_slideshow_image';
  $strongarm->value = 0;
  $export['show_diff_inline_slideshow_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_slideshow_image';
  $strongarm->value = 0;
  $export['show_preview_changes_slideshow_image'] = $strongarm;

  return $export;
}