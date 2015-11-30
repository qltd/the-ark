<?php

if (isset($row->field_field_augmented_links[0]['rendered']['entity']['field_collection_item'])):
  foreach ($row->field_field_augmented_links[0]['rendered']['entity']['field_collection_item'] as $item) {
    $title = isset($item['field_augmented_links_title']['#items'][0]['safe_value']) ?
      $item['field_augmented_links_title']['#items'][0]['safe_value'] :
      '';
    $body = isset($item['field_augmented_links_body']['#items'][0]['safe_value']) ?
      $item['field_augmented_links_body']['#items'][0]['safe_value'] :
      '';
    $image = array(
      'style_name' => 'link_thumbnail',
      'path' => isset($item['field_augmented_links_image']['#items'][0]['uri']) ? $item['field_augmented_links_image']['#items'][0]['uri'] : '',
      'alt' => isset($item['field_augmented_links_image']['#items'][0]['alt']) ? $item['field_augmented_links_image']['#items'][0]['alt'] : '',
      'title' => isset($item['field_augmented_links_image']['#items'][0]['title']) ? $item['field_augmented_links_image']['#items'][0]['title'] : '',
      'attributes' => array(
        'class' => array('augmented-link-image'),
      ),
    );
    $link_title = isset($item['field_augmented_links_link']['#items'][0]['title']) ?
      $item['field_augmented_links_link']['#items'][0]['title'] :
      'Visit Page';
    $link_url = isset($item['field_augmented_links_link']['#items'][0]['url']) ?
      ltrim($item['field_augmented_links_link']['#items'][0]['url'], '/') :
      '';
    $link_attributes = isset($item['field_augmented_links_link']['#items'][0]['attributes']) ?
      $item['field_augmented_links_link']['#items'][0]['attributes'] :
      array();
    $link_query = isset($item['field_augmented_links_link']['#items'][0]['query']) ?
      $item['field_augmented_links_link']['#items'][0]['query'] :
      array();
    $link_attributes['class'] = array('augmented-link-link',);
    $link = !empty($link_url) ?
      l($link_title, $link_url, array(
        'attributes' => $link_attributes,
        'query' => $link_query,
      )) :
      '';
  }
?>

<?php if (!empty($image['path'])) print theme('image_style', $image); ?>
<div class="augmented-link-text">
  <h3 class="augmented-link-title"><?php print $title; ?></h3>
  <?php print $body; ?>
  <?php print $link; ?>
</div>

<?php
endif;
