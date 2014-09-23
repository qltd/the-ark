<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * the-ark theme.
 */
function the_ark_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['actions']['submit'] = array( // replace search submit input tag with button tag
      '#prefix' => '<button type="submit" class="form-submit">',
      '#suffix' => '</button>',
      '#markup' => t('Search'),
    );
  }
}
