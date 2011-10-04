<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */

$plugin = array(
  'title' => t('Taxonomy Term Options'),
  'description' => t('Provides a number of different term related functions to allow for contextualized taxonomy term maintenance.'),
  'required context' => new ctools_context_required(t('Term'), 'taxonomy_term'),
  'content form' => 'context_admin_term_options_menu_content_form',
  'content form submit' => 'context_admin_term_options_menu_content_form_submit',
  'render' => 'context_admin_term_options_menu_render_page',
  'form alter' => 'context_admin_term_options_menu_form_alter',
);

function context_admin_term_options_menu_content_form($form, &$form_state, $cache = NULL) {
  if (!is_null($form_state['handler_id'])) {
    $default_options = isset($form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_term_options']) ? $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_term_options'] : isset($cache->handlers[$form_state['handler_id']]->conf['context_admin_term_options']) ? $cache->handlers[$form_state['handler_id']]->conf['context_admin_term_options'] : NULL;
  }
  else {
    $default_options = $form_state['page']->new_handler->conf['context_admin_term_options'];
  }
  $form['help'] = array(
    '#type' => 'markup',
    '#value' => t('Taxonomy edit tabs can be limited via the access controls/selection criteria.  If they are not limited, they will apply to ALL terms within your site.'),
  );
  $form['context_admin_term_options'] = array(
    '#type' => 'radios',
    '#title' => t('Term Options'),
    '#required' => TRUE,
    '#options' => array(
      'add' => t('Add Sub Term'),
      'term' => t('Edit Term'),
    ),
    '#default_value' => $default_options,
  );
  return $form;
}

function context_admin_term_options_menu_content_form_submit($form, &$form_state) {
  $cache = context_admin_get_page_cache($form_state['page']->subtask_id);
  if (isset($form_state['handler_id'])) {
    $form_state['page']->handlers[$form_state['handler_id']]->conf['context_admin_term_options'] = $form_state['values']['context_admin_term_options'];
  }
  else {
    $form_state['page']->new_handler->conf['context_admin_term_options'] = $form_state['values']['context_admin_term_options'];
  }
  context_admin_set_page_cache($form_state['page']->subtask_id, $form_state['page']);
  return $form_state;
}

function context_admin_term_options_menu_render_page($handler, $base_contexts, $args, $test = TRUE) {
  module_load_include('inc', 'taxonomy', 'taxonomy.admin');
  switch($handler->conf['context_admin_term_options']) {
    case 'add':
      return context_admin_term_options_menu_admin_term_edit($base_contexts[$handler->conf['submitted_context']]->data, TRUE);
    case 'term':
      return context_admin_term_options_menu_admin_term_edit($base_contexts[$handler->conf['submitted_context']]->data);
  }
}

function context_admin_term_options_menu_admin_term_edit($term, $add = NULL) {
  if (isset($add)) {
    return drupal_get_form('taxonomy_form_term', array(), taxonomy_vocabulary_load($term->vid));
  }
  else {
    return drupal_get_form('taxonomy_form_term', $term, taxonomy_vocabulary_load($term->vid));
  }
}

function context_admin_term_options_menu_form_alter(&$form, $form_state, $form_id, $page) {
  if ($page && $form_id == 'taxonomy_form_term') {
    $context = $page['contexts'][$page['handler']->conf['submitted_context']];
    if ($page['handler']->conf['context_admin_term_options'] == 'add' && $context->data->tid) {
      $form['relations']['parent']['#default_value'] = array($context->data->tid);
    }
  }
}
