<?php
/**
 * @file
 * sa_image_slideshow.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sa_image_slideshow_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'image_slide';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Image slide';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'Allow Reordering';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_slideshow_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_slideshow_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollHorz';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_slideshow_image']['id'] = 'field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['table'] = 'field_data_field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['field'] = 'field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['label'] = '';
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['empty'] = 'No image in slideshow';
  $handler->display->display_options['fields']['field_slideshow_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slideshow_image']['settings'] = array(
    'image_style' => 'slideshow_image',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_slideshow_image']['field_api_classes'] = 0;
  /* Sort criterion: DraggableViews: Order */
  $handler->display->display_options['sorts']['value0']['id'] = 'value0';
  $handler->display->display_options['sorts']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['sorts']['value0']['field'] = 'value0';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'slideshow_image' => 'slideshow_image',
  );

  /* Display: Image slideshow */
  $handler = $view->new_display('panel_pane', 'Image slideshow', 'image_slideshow');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';

  /* Display: Reorder slideshow */
  $handler = $view->new_display('panel_pane', 'Reorder slideshow', 'reorder_slideshow');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'reorder-slideshow-images';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'Allow Reordering';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggabletable';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_slideshow_image' => 'field_slideshow_image',
    'title' => 'title',
    'value0' => 'value0',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'field_slideshow_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value0' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['tabledrag_order'] = array(
    'field' => 'value0',
    'handler' => 'native',
  );
  $handler->display->display_options['style_options']['tabledrag_order_visible'] = array(
    'visible' => 0,
  );
  $handler->display->display_options['style_options']['tabledrag_hierarchy'] = array(
    'field' => 'none',
    'handler' => 'native',
  );
  $handler->display->display_options['style_options']['tabledrag_hierarchy_visible'] = array(
    'visible' => 0,
  );
  $handler->display->display_options['style_options']['draggableviews_depth_limit'] = '0';
  $handler->display->display_options['style_options']['tabledrag_expand'] = array(
    'expand_links' => 0,
    'collapsed' => 0,
    'by_uid' => 0,
  );
  $handler->display->display_options['style_options']['draggableviews_extensions'] = array(
    'extension_top' => '3',
    'extension_bottom' => '3',
  );
  $handler->display->display_options['style_options']['tabledrag_lock'] = array(
    'lock' => 0,
  );
  $handler->display->display_options['style_options']['draggableviews_default_on_top'] = '1';
  $handler->display->display_options['style_options']['draggableviews_arguments'] = array(
    'use_args' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_slideshow_image']['id'] = 'field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['table'] = 'field_data_field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['field'] = 'field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['label'] = '';
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['empty'] = 'No image in slideshow';
  $handler->display->display_options['fields']['field_slideshow_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slideshow_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slideshow_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slideshow_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_slideshow_image']['field_api_classes'] = 0;
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
  /* Field: DraggableViews: Order */
  $handler->display->display_options['fields']['value0']['id'] = 'value0';
  $handler->display->display_options['fields']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['fields']['value0']['field'] = 'value0';
  $handler->display->display_options['fields']['value0']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['external'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['value0']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['value0']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value0']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value0']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['value0']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['value0']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value0']['empty_zero'] = 0;
  $handler->display->display_options['fields']['value0']['hide_alter_empty'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
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
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: DraggableViews: Order */
  $handler->display->display_options['sorts']['value0']['id'] = 'value0';
  $handler->display->display_options['sorts']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['sorts']['value0']['field'] = 'value0';
  $handler->display->display_options['sorts']['value0']['expose']['label'] = 'Order';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $export['image_slide'] = $view;

  return $export;
}
