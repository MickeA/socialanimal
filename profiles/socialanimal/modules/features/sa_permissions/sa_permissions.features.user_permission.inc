<?php
/**
 * @file
 * sa_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sa_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'Adminstrator',
      1 => 'Editor',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
