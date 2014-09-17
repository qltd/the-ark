<?php

function the_ark_menu_link ($variables) {
  $variables['element']['#attributes']['class'][] = 'menu-item';
  $variables['element']['#localized_options']['attributes']['class'][] = 'menu-link';
  return theme_menu_link($variables);
}
