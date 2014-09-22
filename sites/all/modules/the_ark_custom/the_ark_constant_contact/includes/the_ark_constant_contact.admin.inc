<?php

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
  $form['the_ark_constant_contact_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Constant Contact Form Text'),
    '#required' => TRUE,
    '#default_value' => variable_get('the_ark_constant_contact_description'),
    '#description' => t('This is the text that appears above the sign up field in the footer.'),
  );
  $form = system_settings_form($form);
  return $form;
}
