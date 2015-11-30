<?php
/**
 * @file
 * Template to display a column
 *
 * - $item: The item to render within a td element.
 */
$calendar_date_raw = arg(2);
$calendar_date = !empty($calendar_date_raw)
  ? date_parse_from_format('Y-m', $calendar_date_raw)
  : array('month' => date('m'),);
$calendar_month = isset($calendar_date['month'])
  ? intval($calendar_date['month'])
  : intval(date('m'));

$item_date_raw = isset($item['date'])
  ? $item['date']
  : date();
$item_date = !empty($item_date_raw)
  ? date_parse_from_format('Y-m-d', $item_date_raw)
  : array('month' => date('m'),);
$item_month = isset($item_date['month'])
  ? intval($item_date['month'])
  : intval(date('m'));

if ($item_month === $calendar_month) {
  $item['class'] .= ' calendar-column-current-month';
} elseif ($item_month < $calendar_month) {
  $item['class'] .= ' calendar-column-previous-month';
} elseif ($item_month > $calendar_month) {
  $item['class'] .= ' calendar-column-next-month';
}

$id = (isset($item['id']))
  ? 'id="' . $item['id'] . '" '
  : '';
$date = ' data-date="' . $item_date_raw . '" ';
$day = (isset($item['day_of_month']))
  ? ' data-day-of-month="' . $item['day_of_month'] . '" '
  : '';
$headers = (isset($item['header_id']))
  ? ' headers="'. $item['header_id'] .'" '
  : '';
?>

<div <?php print $id; ?>class="calendar-column <?php print $item['class'] ?>"<?php print $date . $headers . $day; ?>>
  <div class="calendar-column-inner">
    <div class="calendar-column-date">
      <span class="day-of-month"><?php print $item['day_of_month']; ?></span>
      <span class="day-of-week"><?php print $item['header_id']; ?></span>
    </div>
    <?php print $item['entry']; ?>
  </div>
</div>
