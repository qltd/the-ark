<?php

if (isset($row->field_field_tabs[0]['rendered']['entity']['field_collection_item'])):
  foreach ($row->field_field_tabs[0]['rendered']['entity']['field_collection_item'] as $key => $item) {
    $count = isset($row->field_data_field_tabs_delta) ?
      $row->field_data_field_tabs_delta :
      0;
    $title = isset($item['field_tab_title']['#items'][0]['safe_value']) ?
      $item['field_tab_title']['#items'][0]['safe_value'] :
      'Tab' . ($key + 1);
  }
  ?>

  <a class="tab-toggle" href="#" role="button" data-tab-toggle-id="<?php print $count; ?>"><?php print $title; ?></a>

  <?php
endif;
