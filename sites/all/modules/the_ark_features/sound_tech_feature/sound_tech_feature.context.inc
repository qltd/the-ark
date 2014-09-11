<?php
/**
 * @file
 * sound_tech_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sound_tech_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sound_tech_user_edit';
  $context->description = '';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/sound-tech/users/*/edit' => 'admin/sound-tech/users/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'admin/sound-tech/users',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('admin');
  $export['sound_tech_user_edit'] = $context;

  return $export;
}
