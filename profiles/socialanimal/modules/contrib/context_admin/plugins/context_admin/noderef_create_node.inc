<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
if (module_exists('node_reference')) {
  $plugin = array(
    'title' => t('Create Node with auto node reference'),
    'description' => t('Creates a node with an automatic reference back to its parent.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'content form' => 'context_admin_noderef_create_node_content_form',
    'content form submit' => 'context_admin_noderef_create_node_content_form_submit',
    'render' => 'context_admin_noderef_create_node_render_page',
    'form alter' => 'context_admin_noderef_create_node_form_alter',
  );
}

function context_admin_noderef_create_node_content_form($form, &$form_state, $cache = NULL, $contexts = array()) {
  ctools_include('dependent');
  if (isset($form_state['handler_id'])) {
    $default = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_options_items']) ? 
      $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_options_items'] : 
      isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_options_items']) ? 
        $cache->handlers[$form_state['handler_id']]->conf['context_admin_options_items'] : 
        NULL;
    $type_fields = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_content_types']) ? 
      $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_content_types'] : 
      isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_content_types']) ? 
        $cache->handlers[$form_state['handler_id']]->conf['context_admin_content_types'] : 
        NULL;
    $forward = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_autoforward']) ? 
      $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_autoforward'] : 
      isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_autoforward']) ? 
        $cache->handlers[$form_state['handler_id']]->conf['context_admin_autoforward'] : 
        NULL;
    $custom_redirect = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_custom_redirect']) ? 
      $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_custom_redirect'] : 
      isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_custom_redirect']) ? 
        $cache->handlers[$form_state['handler_id']]->conf['context_admin_custom_redirect'] : 
        NULL;
  }
  else {
    $default = $form_state['page']->new_handler->conf['context_admin_options_items'];
    $type_fields = $form_state['page']->new_handler->conf['context_admin_content_types'];
    $forward = $form_state['page']->new_handler->conf['context_admin_autoforward'];
    $custom_redirect = $form_state['page']->new_handler->conf['context_admin_custom_redirect'];
  }
  $node_entities = entity_get_info('node');
  $types = field_info_instances('node');
  $options = array();
  $fields = array();
  if ($types) {
    foreach ($types as $type => $field_instances) {
      foreach ($field_instances as $field_name => $field) {
        if ($field['display']['default']['type'] == 'node_reference_default') {
          $fields[$type][$field_name] = $field['label'];
          $options[$type] = $node_entities['bundles'][$type]['label'];
        }
      }
    }
  }
  if ($options) {
    $form['context_admin'] = array(
      '#type' => 'fieldset',
      '#title' => t('Node Creation/Reference Options'),
      '#tree' => TRUE,
    );
    $form['context_admin']['context_admin_options_items'] = array(
      '#type' => 'radios',
      '#title' => t('Select the node type you would like to create'),
      '#required' => TRUE,
      '#options' => $options,
      '#default_value' => $default,
    );
    foreach ($fields as $key => $field_group) {
      $form['context_admin']['content_types'][$key] = array(
        '#type' => 'radios',
        '#title' => t('Available Reference Fields'),
        '#description' => t('Choose a reference field from the available fields'),
        '#options' => $field_group,
        '#process' => array('ctools_dependent_process', 'form_process_radios'),
        '#dependency' => array('radio:context_admin[context_admin_options_items]' => array($key)),
        '#prefix' => '<div id="edit-context-admin-content-types-'. str_replace('_', '-', $key) .'-wrapper"><div>',
        '#suffix' => '</div></div>',
        '#default_value' => $type_fields[$key],
      );
    }
    $form['context_admin_autoforward'] = array(
      '#type' => 'checkbox',
      '#title' => t('Forward the user back to the node they were on before they created this node.'),
      '#default_value' => $forward,
    );

    $form['context_admin_custom_redirect'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom redirect path'),
      '#default_value' => $custom_redirect,
      '#description' => t('Define a custom path to redirect to after the node creation. This path will be translated with the node tokens of the parent node. Note: This overrides auto forwarding back to the original node.'),
    );
    $rows = array();
    foreach ($contexts as $context) {
      foreach (ctools_context_get_converters('%' . check_plain($context->keyword) . ':', $context) as $keyword => $title) {
        $rows[] = array(
          check_plain($keyword),
          t('@identifier: @title', array('@title' => $title, '@identifier' => $context->identifier)),
        );
      }
    }

    $header = array(t('Keyword'), t('Value'));
    $form['display_title']['contexts'] = array(
      '#type' => 'fieldset',
      '#title' => t('Substitutions'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#value' => theme('table', array('header' => $header, 'rows' => $rows)),
    );
  }
  else {
    drupal_set_message('There are no node reference fields setup on any existing node types. Please add a node reference field to a node type and try again.', 'error');
  }
  return $form;
}

function context_admin_noderef_create_node_content_form_submit($form, &$form_state) {
  $cache = context_admin_get_page_cache($form_state['page']->subtask_id);
  if (isset($form_state['handler_id']) && isset($form_state['values']['context_admin'])) {
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_options_items'] = $form_state['values']['context_admin']['context_admin_options_items'];
    unset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_content_types']);
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_content_types'][$form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_options_items']] = $form_state['values']['context_admin']['content_types'][$form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_options_items']];
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_field'] = $form_state['values']['context_admin']['content_types'][$form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_options_items']];
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_autoforward'] = $form_state['values']['context_admin_autoforward'];
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_custom_redirect'] = $form_state['values']['context_admin_custom_redirect'];
  }
  elseif (isset($form_state['values']['context_admin'])) {
    $form_state['page']->new_handler->conf['context_admin_options_items'] = $form_state['values']['context_admin']['context_admin_options_items'];
    unset($form_state['page']->new_handler->conf['context_admin_content_types']);
    $form_state['page']->new_handler->conf['context_admin_content_types'][$form_state['page']->new_handler->conf['context_admin_options_items']] = $form_state['values']['context_admin']['content_types'][$form_state['page']->new_handler->conf['context_admin_options_items']];
    $form_state['page']->new_handler->conf['context_admin_field'] = $form_state['values']['context_admin']['content_types'][$form_state['page']->new_handler->conf['context_admin_options_items']];
    $form_state['page']->new_handler->conf['context_admin_autoforward'] = $form_state['values']['context_admin_autoforward'];
    $form_state['page']->new_handler->conf['context_admin_custom_redirect'] = $form_state['values']['context_admin_custom_redirect'];
  }
  context_admin_set_page_cache($form_state['page']->subtask_id, $form_state['page']);
  return $form_state;
}

function context_admin_noderef_create_node_render_page($handler, $base_contexts, $args, $test = TRUE) {
  $page = page_manager_get_current_page();
  $type = $handler->conf['context_admin_options_items'];
  module_load_include('inc', 'node', 'node.pages');
  global $user;

  $types = node_type_get_types();
  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => $type,
    'language' => LANGUAGE_NONE,
    $handler->conf['context_admin_field'] => array('und' => array(0 => array('nid' => $base_contexts[$handler->conf['submitted_context']]->data->nid))),
  );
  drupal_set_title(t('Create @name', array('@name' => $types[$type]->name)), PASS_THROUGH);
  $output = drupal_get_form($type . '_node_form', $node);

  return $output;
}

function context_admin_noderef_create_node_form_alter(&$form, &$form_state, $form_id, $page) {
  switch($form_id) {
    case $page['handler']->conf['context_admin_options_items'] . '_node_form':
      if ($form['#node']->type == $page['handler']->conf['context_admin_options_items']) {
        $form[$page['handler']->conf['context_admin_field']]['#access'] = FALSE;
        $form[$page['handler']->conf['context_admin_field']]['und']['#required'] = FALSE;

        if ($page['handler']->conf['context_admin_autoforward'] || $page['handler']->conf['context_admin_custom_redirect']) {
          $form['page_context'] = array(
            '#type' => 'value',
            '#value' => array(
              'contexts' => $page['contexts'],
              'submitted_context' => $page['handler']->conf['submitted_context'],
            ),
          );

          if ($page['handler']->conf['context_admin_custom_redirect']) {
            $form['context_admin_custom_redirect'] = array(
              '#type' => 'value',
              '#value' => $page['handler']->conf['context_admin_custom_redirect'],
            );
          }

          $form['actions']['submit']['#submit'][] = 'context_admin_noderef_create_node_submit';
        }
      }
      break;
  }
}

function context_admin_noderef_create_node_submit($form, &$form_state) {
  if (isset($form_state['values']['page_context'])) {
    $redirect = '';
    if (isset($form_state['values']['context_admin_custom_redirect']) && $form_state['values']['context_admin_custom_redirect']) {
      $redirect = ctools_context_keyword_substitute($form_state['values']['context_admin_custom_redirect'], array(), $form_state['values']['page_context']['contexts']);
    }
    else {
      $redirect = 'node/' . $form_state['values']['page_context']['contexts'][$form_state['values']['page_context']['submitted_context']]->data->nid;
    }

    if ($redirect) {
      $form_state['redirect'] = $redirect;
    }
  }
}
