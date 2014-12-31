<?php

function the_ark_breadcrumb ($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {

    // Remove column labels that do not contain links from breadcrumbs
    $calendar_crumb = false;
    foreach ($breadcrumb as $key => $crumb) {
      if (strpos($crumb, 'nolink') !== FALSE) {
        unset($breadcrumb[$key]);
      } elseif (
        strpos($crumb, 'Shows &amp; Events') !== FALSE ||
        strpos($crumb, 'Shows & Events') !== FALSE
      ) {
        if ($calendar_crumb === true) {
          unset($breadcrumb[$key]);
          unset($breadcrumb[$key-1]);
        }
        $calendar_crumb = true;
      }
    }

    // Add home link to breadcrumbs that are missing this value
    if (isset($breadcrumb[0]) && strpos($breadcrumb[0], 'Home') === FALSE) {
      array_unshift($breadcrumb, '<a href="/">Home</a>');
    }

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $delimiter = ' <span class="breadcrumb-delimiter">&gt;</span> ';
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<div class="breadcrumb">' . implode($delimiter, $breadcrumb) . $delimiter;
    $output .= l(html_entity_decode(strip_tags(drupal_get_title()), ENT_QUOTES), current_path()) . '</div>';
    return $output;
  } else {
    $output = '<div class="breadcrumb empty-breadcrumb">&nbsp;</div>';
    return $output;
  }
}
