<?php
/**
 * @file
 * sa_music.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sa_music_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sa_music_node_info() {
  $items = array(
    'music' => array(
      'name' => t('Music'),
      'base' => 'node_content',
      'description' => t('Create a node containing a music file. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
