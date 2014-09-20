<?php

use Ctct\ConstantContact;
use Ctct\Components\Contacts\Contact;
use Ctct\Components\Contacts\ContactList;
use Ctct\Components\Contacts\EmailAddress;
use Ctct\Exceptions\CtctException;

function the_ark_constant_contact_block_info() {
  $blocks['the_ark_constant_contact'] = array(
    'info' => t('The Ark Constant Contact Form'),
  );
  return $blocks;
}

function the_ark_constant_contact_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'the_ark_constant_contact':
      $block['subject'] = null;
      $block['content'] = drupal_get_form('the_ark_constant_contact_contacts_form');
      break;
  }
  return $block;
}

function the_ark_constant_contact_contacts_form ($form, &$form_state) {
  $form = array();
  $form['constant_contact_form_header'] = array(
    '#markup' => t('<p class="constant-contact-paragraph">Get updates on upcoming shows, Ark news, and more. Your information is safe with us.</p>'),
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#attributes' =>array(
      'placeholder' => t('Email Address'),
    ),
    '#required' => true,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign Up'),
  );
  return $form;
}

function the_ark_constant_contact_contacts_form_submit ($form, &$form_state) {
  $email = isset($form_state['values']['email']) ? $form_state['values']['email'] : '';
  if (empty($email)) return;

  $api_key = variable_get('the_ark_constant_contact_api_key');
  $access_token = variable_get('the_ark_constant_contact_access_token');
  if (empty($api_key) || empty($access_token)) return;

  try {
    $cc = new ConstantContact($api_key);
    $response = $cc->getContactByEmail($access_token, $email);

    if (!isset($response->results[0])) {
      $contact = new Contact();
      $contact->addEmail($email);
      $contact->addList('1');
      $returnContact = $cc->addContact($access_token, $contact, true);
      watchdog('the_ark_constant_contact', 'Constant Contact: Added contact %email', array('%email' => $email), WATCHDOG_INFO);
    } else {
      watchdog('the_ark_constant_contact', 'Constant Contact: Duplicate contact %email', array('%email' => $email), WATCHDOG_NOTICE);
    }
    drupal_set_message(t('Thank you! You will now receive regular updates from The Ark.'));

  } catch (CtctException $ex) {
    $cc_errors = $ex->getErrors();
    $error_message = isset($cc_errors[0]['error_message'])
      ? $cc_errors[0]['error_message']
      : 'Constant Contact form submission error';
    watchdog('the_ark_constant_contact', $error_message, array(), WATCHDOG_ERROR);
  }
}
