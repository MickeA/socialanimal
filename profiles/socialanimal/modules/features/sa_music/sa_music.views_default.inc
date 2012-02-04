<?php
/**
 * @file
 * sa_music.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sa_music_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'music_player';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Music player';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: hide-show */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'hide-show';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="player-hide-show">Hide</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Add/edit music';
  /* Field: Content: Cover/Image */
  $handler->display->display_options['fields']['field_music_image']['id'] = 'field_music_image';
  $handler->display->display_options['fields']['field_music_image']['table'] = 'field_data_field_music_image';
  $handler->display->display_options['fields']['field_music_image']['field'] = 'field_music_image';
  $handler->display->display_options['fields']['field_music_image']['label'] = '';
  $handler->display->display_options['fields']['field_music_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['text'] = '[field_music_image] [title]';
  $handler->display->display_options['fields']['field_music_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_music_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_music_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_music_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_music_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_music_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_music_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_music_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_music_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_music_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_music_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_music_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Music file */
  $handler->display->display_options['fields']['field_music_file_1']['id'] = 'field_music_file_1';
  $handler->display->display_options['fields']['field_music_file_1']['table'] = 'field_data_field_music_file';
  $handler->display->display_options['fields']['field_music_file_1']['field'] = 'field_music_file';
  $handler->display->display_options['fields']['field_music_file_1']['label'] = '';
  $handler->display->display_options['fields']['field_music_file_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_music_file_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_music_file_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_music_file_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_music_file_1']['type'] = 'jplayer_player';
  $handler->display->display_options['fields']['field_music_file_1']['settings'] = array(
    'mode' => 'playlist',
    'autoplay' => '0',
    'solution' => 'html, flash',
    'preload' => 'metadata',
    'volume' => '80',
    'muted' => '0',
    'repeat' => 'none',
    'backgroundColor' => '000000',
  );
  $handler->display->display_options['fields']['field_music_file_1']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_music_file_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_music_file_1']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_music_file_1']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['music_player'] = $view;

  return $export;
}
