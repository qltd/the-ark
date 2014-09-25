<?php

function the_ark_preprocess_html (&$variables) {
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/libraries/jquery.browser/dist/jquery.browser.min.js',
    array(
      'group' => JS_LIBRARY
    )
  );
  drupal_add_js(drupal_get_path('theme', 'the_ark') . '/libraries/Tocca.js/Tocca.min.js',
    array(
      'group' => JS_LIBRARY
    )
  );

  // Add conditional stylesheets for IE
  drupal_add_css(drupal_get_path('theme', 'the_ark') . '/css/the-ark.lte-ie8.min.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 8',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE
    )
  );
}
