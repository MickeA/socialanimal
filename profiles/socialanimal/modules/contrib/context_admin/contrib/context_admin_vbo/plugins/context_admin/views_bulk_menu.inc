<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */

$plugin = array(
  'title' => t('Views Administration'),
  'description' => t('Provides a generic Views Bulk Operations based view that should work for most node type needs.'),
  'content form' => 'context_admin_vbo_views_bulk_menu_content_form',
  'content form submit' => 'context_admin_vbo_views_bulk_menu_content_form_submit',
  'render' => 'context_admin_vbo_views_bulk_menu_render_page',
  'save' => 'context_admin_vbo_views_bulk_menu_save',
  'delete' => 'context_admin_vbo_views_bulk_menu_delete',
);

function context_admin_vbo_views_bulk_menu_content_form($form, &$form_state, $cache = NULL) {
  if (!is_null($form_state['handler_id'])) {
    $machine_name = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_machine_name']) ? $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_machine_name'] : isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_vbo_machine_name']) ? $cache->handlers[$form_state['handler_id']]->conf['context_admin_vbo_machine_name'] : NULL;
    $default_type = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_node_type']) ? $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_node_type'] : isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_node_type']) ? $cache->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_node_type'] : NULL;
    $default_pub = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_published']) ? $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_published'] : isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_published']) ? $cache->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_published'] : NULL;
  }
  else {
    $machine_name = $form_state['page']->new_handler->conf['context_admin_vbo_machine_name'];
    $default_type = $form_state['page']->new_handler->conf['context_admin_vbo_views_bulk_node_type'];
    $default_pub = $form_state['page']->new_handler->conf['context_admin_vbo_views_bulk_published'];
  }
  $node_entities = entity_get_info('node');
  $types = field_info_instances('node');
  foreach ($types as $type => $field_instances) {
    $options[$type] = $node_entities['bundles'][$type]['label'];
  }
  $form['context_admin_vbo_machine_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Views: Machine Name'),
    '#description' => t('A unique machine-readable name for this View. It must only contain lowercase letters, numbers, and underscores.'),
    '#required' => TRUE,
    '#default_value' => $machine_name,
  );
  $form['context_admin_vbo_views_bulk_node_type'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node Type'),
    '#required' => TRUE,
    '#options' => $options,
    '#default_value' => $default_type,
  );
  $form['context_admin_vbo_views_bulk_published'] = array(
    '#type' => 'radios',
    '#title' => t('Published Options'),
    '#required' => TRUE,
    '#options' => array(
      'published' => t('Published'),
      'unpublished' => t('Unpublished'),
      'both' => t('both'),
    ),
    '#default_value' => $default_pub,
  );
  return $form;
}

function context_admin_vbo_views_bulk_menu_content_form_submit($form, $form_state) {
  $cache = context_admin_get_page_cache($form_state['page']->subtask_id);
  if (!is_null($form_state['handler_id'])) {
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_machine_name'] = $form_state['values']['context_admin_vbo_machine_name'];
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_node_type'] = $form_state['values']['context_admin_vbo_views_bulk_node_type'];
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_vbo_views_bulk_published'] = $form_state['values']['context_admin_vbo_views_bulk_published'];
  }
  else {
    $form_state['page']->new_handler->conf['context_admin_vbo_machine_name'] = $form_state['values']['context_admin_vbo_machine_name'];
    $form_state['page']->new_handler->conf['context_admin_vbo_views_bulk_node_type'] = $form_state['values']['context_admin_vbo_views_bulk_node_type'];
    $form_state['page']->new_handler->conf['context_admin_vbo_views_bulk_published'] = $form_state['values']['context_admin_vbo_views_bulk_published'];
  }
  context_admin_set_page_cache($form_state['page']->subtask_id, $form_state['page']);
  return $form_state;
}

function context_admin_vbo_views_bulk_menu_render_page($handler, $base_contexts, $args, $test = TRUE) {
  return views_embed_view($handler->conf['context_admin_vbo_machine_name']);
}

function context_admin_vbo_views_bulk_menu_save($handler, $update) {
  views_invalidate_cache();
}

function context_admin_vbo_views_bulk_menu_delete($handler) {
  views_invalidate_cache();
}

