<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * the-ark theme.
 */
function the_ark_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['actions']['desktop_submit'] = array( // replace search submit input tag with button tag
      '#prefix' => '<button type="submit" class="form-submit-desktop">',
      '#suffix' => '</button>',
      '#markup' => t('Search'),
    );
    $form['actions']['submit'] = array( // replace search submit input tag with button tag
      '#prefix' => '<button type="submit" class="form-submit">',
      '#suffix' => '</button>',
      '#markup' => t('Search'),
    );
  }
}

function the_ark_css_alter(&$css) {
  $calendar_path = drupal_get_path('module', 'calendar');
  $date_path = drupal_get_path('module', 'date');

  unset($css[$calendar_path . '/css/calendar_multiday.css']);
  unset($css[$date_path . '/date_views/css/date_views.css']);
}
