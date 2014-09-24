<?php

function the_ark_menu_tree__main_menu ($variables) {
  if (strpos($variables['tree'], 'menu-top-level-item') === false)
    return theme_menu_tree($variables);
  return '<div class="menu-primary-wrapper"><ul class="menu">' . $variables['tree'] . '</ul></div>';
}
