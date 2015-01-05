<?php

if (isset($row->field_field_tabs[0]['rendered']['entity']['field_collection_item'])):
  foreach ($row->field_field_tabs[0]['rendered']['entity']['field_collection_item'] as $key => $item) {
    $count = isset($row->field_data_field_tabs_delta) ?
      $row->field_data_field_tabs_delta :
      0;
    $title = isset($item['field_tab_title']['#items'][0]['safe_value']) ?
      $item['field_tab_title']['#items'][0]['safe_value'] :
      'Tab' . ($key + 1);
    $body = isset($item['field_tab_body']['#items'][0]['safe_value']) ?
      $item['field_tab_body']['#items'][0]['safe_value'] :
      '';
  }
?>

<div class="tab-container" data-tab-id="<?php print $count; ?>">
  <h2 class="tab-title expander"><?php print $title; ?></h2>
  <div class="tab-content expander-content">
    <div class="tab-content-body">
      <?php print $body; ?>
    </div>
  </div>
</div>

<?php
endif;
