<?php

function the_ark_constant_contact_admin () {
  return drupal_get_form('the_ark_constant_contact_admin_form');
}

function the_ark_constant_contact_admin_form ($form, &$form_state) {
  $form = array();
  $form['the_ark_help'] = array(
    '#markup' => t('Set the API key and access token for Constant Contact integration.'),
  );
  $form['the_ark_constant_contact_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Constant Contact API Key'),
    '#required' => TRUE,
    '#default_value' => variable_get('the_ark_constant_contact_api_key'),
  );
  $form['the_ark_constant_contact_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Constant Contact Access Token'),
    '#required' => TRUE,
    '#default_value' => variable_get('the_ark_constant_contact_access_token'),
  );
  $form = system_settings_form($form);
  return $form;
}
