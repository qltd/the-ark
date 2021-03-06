<?php

function sound_tech_edit_user_access ($uid) {
  global $user;
  if ($user->uid === $uid || user_access('manage sound tech user accounts')) return true;
  return false;
}

function sound_tech_edit_user_title ($uid) {
  $sound_tech_user = user_load($uid);
  return isset($sound_tech_user->name) ? 'Edit ' . $sound_tech_user->name . '\'s Sound Tech User Account' : '';
}

function sound_tech_show_user ($uid) {
  drupal_goto('user/' . $uid);
}

function sound_tech_edit_user ($uid) {
  $sound_tech_user = user_load($uid);
  if (empty($sound_tech_user)) return drupal_not_found();
  unset($sound_tech_user->pass);
  $sound_tech_user = (array) $sound_tech_user;
  $roles = $sound_tech_user['roles'];
  if (!isset($roles[5]) || count($roles) !== 2) return drupal_not_found();
  return drupal_get_form('sound_tech_user_form', $sound_tech_user);
}

function sound_tech_user_form ($form, &$form_state, $sound_tech_user = array()) {
  $form = array();
  $form['uid'] = array(
    '#type' => 'hidden',
    '#value' => isset($sound_tech_user['uid']) ? $sound_tech_user['uid'] : '',
  );
  $form['name'] = array(
    '#type' => 'fieldset',
    '#title' => t('Name'),
  );
  $form['name']['name_first'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#required' => true,
    '#default_value' => isset($sound_tech_user['field_name_first']['und'][0]['value'])
      ? $sound_tech_user['field_name_first']['und'][0]['value']
      : '',
  );
  $form['name']['name_middle'] = array(
    '#type' => 'textfield',
    '#title' => t('Middle Name (optional)'),
    '#default_value' => isset($sound_tech_user['field_name_middle']['und'][0]['value'])
      ? $sound_tech_user['field_name_middle']['und'][0]['value']
      : '',
  );
  $form['name']['name_last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#required' => true,
    '#default_value' => isset($sound_tech_user['field_name_last']['und'][0]['value'])
      ? $sound_tech_user['field_name_last']['und'][0]['value']
      : '',
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => isset($sound_tech_user['mail']) ? $sound_tech_user['mail'] : '',
    '#required' => true,
  );
  $form['sound_tech_duty'] = array(
    '#type' => 'radios',
    '#options' => array(
      '_none' => t('N/A'),
      'regular' => t('Regular Lead Tech Duty'),
      'reserve' => t('Reserve Lead Tech Duty'),
      'retired' => t('Retired'),
      'assistant' => t('Assistant'),
    ),
    '#title' => t('Sound Tech Duty'),
    '#default_value' => isset($sound_tech_user['field_sound_tech_duty']['und'][0]['value'])
      ? $sound_tech_user['field_sound_tech_duty']['und'][0]['value']
      : '',
  );
  $form['phone'] = array(
    '#type' => 'fieldset',
    '#title' => t('Phone Numbers'),
  );
  $form['phone']['phone_home'] = array(
    '#type' => 'textfield',
    '#title' => t('Home'),
    '#default_value' => isset($sound_tech_user['field_phone_home']['und'][0]['value'])
      ? $sound_tech_user['field_phone_home']['und'][0]['value']
      : '',
  );
  $form['phone']['phone_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile'),
    '#default_value' => isset($sound_tech_user['field_phone_mobile']['und'][0]['value'])
      ? $sound_tech_user['field_phone_mobile']['und'][0]['value']
      : '',
  );
  $form['phone']['phone_work'] = array(
    '#type' => 'textfield',
    '#title' => t('Work'),
    '#default_value' => isset($sound_tech_user['field_phone_work']['und'][0]['value'])
      ? $sound_tech_user['field_phone_work']['und'][0]['value']
      : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

// function sound_tech_user_form_validate (&$elements, &$form_state) {
//
// }

function sound_tech_user_form_submit ($form, &$form_state) {
  $values = isset($form_state['values']) ? $form_state['values'] : array();
  $full_name = array();
  if (!empty($values['name_first'])) $full_name['first'] = $values['name_first'];
  if (!empty($values['name_middle'])) $full_name['middle'] = $values['name_middle'];
  if (!empty($values['name_last'])) $full_name['last'] = $values['name_last'];

  $user_fields = array(
    'name' => implode(' ', $full_name),
    'mail' => $values['email'],
    'roles' => array(
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
      5 => 'sound tech',
    ),
    'status' => 1,
    'init' => $values['email'],
  );

  if (empty($values['uid'])) { // new accounts
    $user_fields['pass'] = user_password(8); // set random password
  } else { // existing accounts
    $sound_tech_user = user_load($values['uid']);
    if (isset($sound_tech_user->roles)) $user_fields['roles'] = $sound_tech_user->roles;
  }

  if (!empty($values['sound_tech_duty']) && $values['sound_tech_duty'] !== '_none')
    $user_fields['field_sound_tech_duty']['und'][0]['value'] = $values['sound_tech_duty'];
  else $user_fields['field_sound_tech_duty'] = array();

  if (!empty($values['name_first']))
    $user_fields['field_name_first']['und'][0]['value'] = $values['name_first'];
  else $user_fields['field_name_first'] = array();
  if (!empty($values['name_middle']))
    $user_fields['field_name_middle']['und'][0]['value'] = $values['name_middle'];
  else $user_fields['field_name_middle'] = array();
  if (!empty($values['name_last']))
    $user_fields['field_name_last']['und'][0]['value'] = $values['name_last'];
  else $user_fields['field_name_last'] = array();

  if (!empty($values['phone_home']))
    $user_fields['field_phone_home']['und'][0]['value'] = $values['phone_home'];
  else $user_fields['field_phone_home'] = array();
  if (!empty($values['phone_mobile']))
    $user_fields['field_phone_mobile']['und'][0]['value'] = $values['phone_mobile'];
  else $user_fields['field_phone_mobile'] = array();
  if (!empty($values['phone_work']))
    $user_fields['field_phone_work']['und'][0]['value'] = $values['phone_work'];
  else $user_fields['field_phone_work'] = array();

  user_save(empty($values['uid']) ? null : (object) array('uid' => $values['uid']), $user_fields);
  drupal_goto('admin/sound-tech/people');
}
