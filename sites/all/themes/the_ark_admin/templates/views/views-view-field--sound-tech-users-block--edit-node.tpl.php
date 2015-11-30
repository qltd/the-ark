<?php

/**
 * Edit link field for sound tech users view
 */

global $user;

$user_roles = isset($row->_field_data['uid']['entity']->roles)
  ? $row->_field_data['uid']['entity']->roles
  : array();
$user_id = isset($row->_field_data['uid']['entity']->uid)
  ? $row->_field_data['uid']['entity']->uid
  : '';
$edit_link = isset($field->last_render)
  ? $field->last_render
  : '';

if (isset($user_roles[5]) && count($user_roles) === 2) {
  if (isset($user->roles[4]) || isset($user->roles[3]) || $user->uid === $user_id) {
    print l(t('edit'), 'admin/sound-tech/people/'. $user_id .'/edit');
  }
} elseif ($user->uid === $user_id) {
  print $edit_link;
}
