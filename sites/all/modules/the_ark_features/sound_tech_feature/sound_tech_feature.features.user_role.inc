<?php
/**
 * @file
 * sound_tech_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sound_tech_feature_user_default_roles() {
  $roles = array();

  // Exported role: sound tech.
  $roles['sound tech'] = array(
    'name' => 'sound tech',
    'weight' => 2,
  );

  // Exported role: sound tech administrator.
  $roles['sound tech administrator'] = array(
    'name' => 'sound tech administrator',
    'weight' => 3,
  );

  return $roles;
}
