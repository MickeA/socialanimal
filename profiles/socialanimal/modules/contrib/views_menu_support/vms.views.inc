<?php
/**
 * @file
 * Declares the Views plugin for inheriting argument value.
 */

/**
 * Implements hook_views_plugins().
 */
function vms_views_plugins() {
  return array(
    'argument default' => array(
      'vms_current_mlid' => array(
        'title' => t('Currently active menu item link ID'),
        'handler' => 'vms_plugin_argument_default_mlid',
      ),
    ),
  );
}

function vms_views_data_alter(&$data) {
  // Get a list of all integer fields on the site – only these should be used
  // for MLID filtering.
  foreach (field_info_fields() as $field) {
    if ($field['type'] == 'number_integer') {
      // Get a quick alias for the field name, for readability
      $field = &$field['field_name'];

      $data['field_data_' . $field]['vms_' . $field] = array(
        'group' => t('MLID filtering'),
        'title' => t('@field', array('@field' => $field)),
        'field' => $field . '_value',
        'filter' => array(
          'field' => $field . '_value',
          'table' => 'field_data_' . $field,
          'help' => t('A filter treating the field as a MLID value, matching it
            against active menu link IDs.'),
          'handler'  => 'vms_handler_filter_mlid',
        ),
      );
    }
  }
}

/**
 * Implements hook_views_query_alter().
 *
 * This function is used instead of hook_views_query_substitutions, since it
 * has to change not only filter values, but also operators.
 */
function vms_views_query_alter($view, $query) {
  // Get the patterns we want to replace.
  $replacements = array_keys(vms_mlid_query_types());

  foreach ($query->where as &$condition_group) {
    foreach ($condition_group['conditions'] as &$condition) {
      if (in_array($condition['value'], $replacements)) {
        $condition['operator'] = ($condition['operator'] == '=') ? 'IN' : 'NOT IN';
        $condition['value'] = vms_get_current_mlid($condition['value']);
      }
    }
  }
}
