<?php

function the_ark_preprocess_html (&$variables) {
  // Add conditional stylesheets for IE
  drupal_add_css(drupal_get_path('theme', 'the_ark') . '/css/the-ark.lte-ie8.min.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));

}