<?php

/**
 * Duty/position field for sound tech users view
 */

if (isset($field->original_value))
  $duty = $field->original_value;
elseif (isset($row->_field_data['uid']['entity']->field_position['und'][0]['safe_value']))
  $duty = $row->_field_data['uid']['entity']->field_position['und'][0]['safe_value'];
else $duty = '';

print $duty;
