<?php


function the_ark_admin_preprocess_html (&$variables) {
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/libraries/jquery.browser/dist/jquery.browser.js',
    array(
      'group' => JS_LIBRARY
    )
  );
}
