<?php
/**
 * @file
 * sa_music.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function sa_music_filter_default_formats() {
  $formats = array();

  // Exported format: HTML
  $formats['html'] = array(
    'format' => 'html',
    'name' => 'HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(),
  );

  return $formats;
}
