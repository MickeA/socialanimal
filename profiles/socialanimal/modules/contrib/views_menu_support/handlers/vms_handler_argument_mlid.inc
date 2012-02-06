<?php

/**
 * @file
 * Contains the argument handler for checking against current mlid.
 *
 * THIS FILE IS NOT USED. KEPT FOR DEVELOPMENT AND SENTIMENTAL REASONS ONLY.
 */

/**
 * Argument handler for comparing a numerical field against current mlid.
 *
 * @ingroup views_argument_handlers
 */
//class vms_handler_argument_mlid extends views_handler_argument_numeric {
//  function option_definition() {
//    $options = parent::option_definition();
//
//    // Allow multiple values as standard.
//    $options['break_phrase'] = array('default' => TRUE);
//
//    $options['cascade_field'] = NULL;
//
//    return $options;
//  }
//
//  function options_form(&$form, &$form_state) {
//    parent::options_form($form, $form_state);
//
//    $options = array(FALSE => t('Don\'t include parents'));
//    foreach ($this->view->display_handler->default_display->display->display_options['fields'] as &$field) {
//      $options[$field['id']] = (empty($field['label'])) ? $field['id'] : $field['label'];
//    }
//    $form['cascade_field'] = array(
//      '#type' => 'select',
//      '#title' => t('Include parent items where the following field is TRUE'),
//      '#description' => t('To use this, the \'Allow multiple values\' option must also be checked.'),
//      '#options' => $options,
//      '#default_value' => $this->options['cascade_field'],
//      '#fieldset' => 'more',
//    );
//  }
//  /**
//   * Override for specific title lookups.
//   */
//  function title_query() {
//    return $this->value;
//  }
//
//}
