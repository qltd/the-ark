<?php

/**
 * Sound tech stage plot(s) field for sound tech events view
 */

$stage_plots = isset($row->_field_data['field_event_node_nid']['entity']->field_stage_plot['und'])
  ? $row->_field_data['field_event_node_nid']['entity']->field_stage_plot['und']
  : array();
?>

<?php if (count($stage_plots) !== 0): ?>
  <div class="item-list">
    <ul>
  <?php foreach ($stage_plots as $stage_plot): ?>
      <li>
        <?php print l(t('view'), file_create_url($stage_plot['uri']), array('attributes' => array('target' => '_blank', 'title' => $stage_plot['filename'],),)); ?>
      </li>
  <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>
