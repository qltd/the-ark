<?php

function the_ark_menu_link ($variables) {
  $variables['element']['#attributes']['class'][] = 'menu-item';
  $variables['element']['#localized_options']['attributes']['class'][] = 'menu-link';

  $primary = array( // main menu top-level links with dropdowns
    'About' => 'node/2',
    'Contact Us' => 'node/5',
    'Shows & Events' => 'node/1',
    'Support the Ark' => 'node/3',
  );

  if ($variables['element']['#theme'] === 'menu_link__main_menu' && in_array($variables['element']['#href'], $primary))
    return the_ark_primary_navigation_content($variables['element']);
  return theme_menu_link($variables);
}

function the_ark_primary_navigation_content ($element) {
  $menu_item = l($element['#title'], $element['#href'], $element['#localized_options']);
  $sub_menu = isset($element['#below']) ? drupal_render($element['#below']) : '';
  $markup = the_ark_primary_navigation_related_links(str_replace('node/', '', $element['#href']));
  switch ($element['#href']) {
    case 'node/2': // About
      $markup .= the_ark_block_in_menu_render('block', '3');
      break;
    case 'node/5': // Contact Us
      $markup .= the_ark_block_in_menu_render('block', '4');
      break;
    case 'node/1': // Shows & Events
      $markup .= the_ark_block_in_menu_render('block', '5');
      break;
    case 'node/3': // Support the Ark
      $markup .= the_ark_block_in_menu_render('block', '6');
      break;
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $menu_item . $sub_menu . $markup . "</li>\n";
}

function the_ark_primary_navigation_related_links ($nid) {
  $markup = '';
  $node = node_load($nid);
  if (!isset($node->field_related_page['und'])) return $markup;
  $related_pages = $node->field_related_page['und'];
  $markup .= '<div class="header-navigation-related-links header-navigation-block">';
  $markup .= '<h3 class="related-links-title">Related</h3>';
  $markup .= '<ul class="related-links-menu">';
  foreach ($related_pages as $key => $value) {
    if (isset($value['target_id'])) {
      $page = node_load($value['target_id']);
      if (isset($page->title)) {
        $markup .= '<li class="related-links-menu-item">';
        $markup .= l($page->title, 'node/' . $value['target_id'], array(
          'attributes' => array(
            'class' => array('related-links-menu-link'),
          )
        ));
        $markup .= '</li>';
      }
    }
  }
  $markup .= '</ul></div>';
  return $markup;
}

function the_ark_block_in_menu_render ($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);
  return $block_rendered;
}
