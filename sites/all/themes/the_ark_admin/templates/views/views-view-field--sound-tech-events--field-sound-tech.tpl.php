<?php

/**
 * Sound tech user field for sound tech events view
 */

$sound_techs = isset($row->_field_data['field_event_node_nid']['entity']->field_sound_tech['und'])
  ? $row->_field_data['field_event_node_nid']['entity']->field_sound_tech['und']
  : array();
?>

<?php if (count($sound_techs) !== 0): ?>
  <div class="item-list">
    <ul>
  <?php foreach ($sound_techs as $key => $sound_tech): ?>
    <?php if (isset($sound_tech['target_id'])): ?>
      <?php $sound_tech = user_load($sound_tech['target_id']); ?>
      <li><?php print $sound_tech->name; ?>
      <?php if (isset($sound_tech->field_sound_tech_duty['und'][0]['value'])): ?>
        &ndash;&nbsp;<strong><?php print ucfirst($sound_tech->field_sound_tech_duty['und'][0]['value']); ?></strong>
      <?php endif;?>
      </li>
    <?php endif; ?>
  <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>
