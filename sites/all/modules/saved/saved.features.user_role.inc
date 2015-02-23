<?php
/**
 * @file
 * saved.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function saved_user_default_roles() {
  $roles = array();

  // Exported role: Content Administrator.
  $roles['Content Administrator'] = array(
    'name' => 'Content Administrator',
    'weight' => 10,
  );

  // Exported role: Content Editor.
  $roles['Content Editor'] = array(
    'name' => 'Content Editor',
    'weight' => 9,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  return $roles;
}
