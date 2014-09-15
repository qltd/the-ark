<?php

/**
 * Edit link field for sound tech events view
 */

global $user;

$event_id = isset($row->_field_data['nid']['entity']->nid)
  ? $row->_field_data['nid']['entity']->nid
  : '';
$edit_link = isset($field->last_render)
  ? $field->last_render
  : '';

if (!empty($edit_link)) {
  print $edit_link;
} elseif (!empty($event_id) && (isset($user->roles[4]) || isset($user->roles[3]))) {
  print l(t('edit'), 'admin/sound-tech/events/' . $event_id . '/edit');
}
