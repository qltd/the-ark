<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

$event = isset($row->_field_data['nid']['entity']) ?
  $row->_field_data['nid']['entity'] :
  array();

$sold_out = isset($event->field_sold_out['und'][0]['value']) ?
  $event->field_sold_out['und'][0]['value'] :
  '0';

$ticket = isset($event->field_ticket_url['und'][0]) ?
  $event->field_ticket_url['und'][0] :
  array();

$attributes = isset($ticket['attributes']) ?
  $ticket['attributes'] :
  array();

$attributes['target'] = '_blank';
$attributes['class'][] = 'tickets-link';
if ($sold_out === '1') {
  $attributes['class'][] = 'tickets-link-sold-out';
  $ticket['title'] = 'Sold Out';
}

?>

<?php if (isset($ticket['url']) && $ticket['url'] !== 'null'): ?>
  <?php print l($ticket['title'], $ticket['url'], array(
    'attributes' => $attributes
  )); ?>
<?php else: ?>
  <span class="tickets-no-link">Tickets not available online</span>
<?php endif; ?>
