<?php
/**
 * @file
 * Template to display a row
 *
 * - $inner: The rendered string of the row's contents.
 */
$attrs = ($class) ? 'class="calendar-row ' . $class . '"': '';
$attrs .= ($iehint > 0) ? ' iehint="' . $iehint . '"' : '';

if (isset($class) && $class === 'single-day'):
?>
  <div <?php print $attrs; ?>>
    <?php print $inner; ?>
  </div>
<?php endif; ?>
