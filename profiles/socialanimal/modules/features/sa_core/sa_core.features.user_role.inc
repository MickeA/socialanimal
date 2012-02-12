<?php
/**
 * @file
 * sa_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sa_core_user_default_roles() {
  $roles = array();

  // Exported role: Adminstrator
  $roles['Adminstrator'] = array(
    'name' => 'Adminstrator',
    'weight' => '3',
  );

  // Exported role: Editor
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => '2',
  );

  return $roles;
}
