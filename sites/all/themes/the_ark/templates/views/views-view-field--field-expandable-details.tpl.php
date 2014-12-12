<?php

if (isset($row->field_field_expandable_details[0]['rendered']['entity']['field_collection_item'])):
  foreach ($row->field_field_expandable_details[0]['rendered']['entity']['field_collection_item'] as $item) {


    $prefix = isset($item['field_expandable_details_prefix']['#items'][0]['safe_value']) ?
      '<span class="expandable-details-title-prefix">' .
        $item['field_expandable_details_prefix']['#items'][0]['safe_value'] .
        '</span> ' :
      '';
    $title = isset($item['field_expandable_details_title']['#items'][0]['safe_value']) ?
      $prefix . $item['field_expandable_details_title']['#items'][0]['safe_value'] :
      '';
    $details = isset($item['field_expandable_details_details']['#items']) ?
      $item['field_expandable_details_details']['#items'] :
      array();
    $expand_label = isset($item['field_expandable_details_expand']['#items'][0]['safe_value']) ?
      $item['field_expandable_details_expand']['#items'][0]['safe_value'] :
      'View';
    $link_title = isset($item['field_expandable_details_link']['#items'][0]['title']) ?
      $item['field_expandable_details_link']['#items'][0]['title'] :
      '';
    $link_url = isset($item['field_expandable_details_link']['#items'][0]['url']) ?
      ltrim($item['field_expandable_details_link']['#items'][0]['url'], '/') :
      '';
    $link_attributes = isset($item['field_expandable_details_link']['#items'][0]['attributes']) ?
      $item['field_expandable_details_link']['#items'][0]['attributes'] :
      array();
    $link_attributes['class'] = array('expandable-details-link',);
    $link = !empty($link_url) ?
      l($link_title, $link_url, array(
        'attributes' => $link_attributes,
      )) :
      '<span class="expandable-details-no-link">'. $link_title .'</span>';
  }
?>

<div class="expandable-details-text">
  <h3 class="expandable-details-title"><?php print $title; ?></h3>
  <ul class="expandable-details-list">
    <?php foreach ($details as $detail): ?>
      <li class="expandable-details-list-item">
        <?php print isset($detail['safe_value']) ? $detail['safe_value'] : '' ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
<?php print $link; ?>
<a class="expandable-details-expander" role="button" data-expander-label="<?php print $expand_label; ?>">Close <?php print $expand_label; ?></a>

<?php
endif;
