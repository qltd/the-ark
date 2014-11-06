<?php
/**
 * @file
 * Template to display a column
 *
 * - $item: The item to render within a td element.
 */
$id = (isset($item['id'])) ? 'id="' . $item['id'] . '" ' : '';
$date = (isset($item['date'])) ? ' data-date="' . $item['date'] . '" ' : '';
$day = (isset($item['day_of_month'])) ? ' data-day-of-month="' . $item['day_of_month'] . '" ' : '';
$headers = (isset($item['header_id'])) ? ' headers="'. $item['header_id'] .'" ' : '';
?>
<div <?php print $id; ?>class="calendar-column <?php print $item['class'] ?>"<?php print $date . $headers . $day; ?>>
  <div class="calendar-column-inner">
    <span class="calendar-column-date"><?php print $item['day_of_month']; ?></span>
    <?php print $item['entry']; ?>
  </div>
</div>
