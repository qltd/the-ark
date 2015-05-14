<?php
/**
 * @file
 * basic_page_content.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function basic_page_content_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Static map image of The Ark location with links.';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'ark_map';
  $fe_block_boxes->body = '<article class="ark-map">
  <h2 class="ark-map-title">Find us on the map!</h2>
  <a href="https://goo.gl/maps/umo04" target="_blank"><img alt="the ark on google maps" src="/sites/all/themes/the_ark/images/ark-map-img.png"></a>
  <ul class="ark-map-list">
      <li class="ark-map-list-item map-item-first">
        <a class="ark-map-link" href="https://goo.gl/maps/umo04" target="_blank">View on Google Maps</a>
      </li>
      <li class="ark-map-list-item map-item-last">
        <a class="ark-map-link" href="/contact/directions-parking">Directions &amp; Parking</a>
      </li>
  </ul>
</article>';

  $export['ark_map'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'List of icons for the membership page.';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'membership_icon_list';
  $fe_block_boxes->body = '<ul class="icon-list">
      <li class="icon-list-item">
        <div class="icon-wrap heart icon-replace">Heart</div>
        <div class="icon-item-title">Reason #1</div>
        <div class="icon-item-copy">You Love The Ark!</div>
      </li>
      <li class="icon-list-item">
        <div class="icon-wrap print-calendar icon-replace">Calendar</div>
        <div class="icon-item-title">Reason #2</div>
        <div class="icon-item-copy">The Printed Calendar</div>
      </li>
      <li class="icon-list-item">
        <div class="icon-wrap discount icon-replace">Discount</div>
        <div class="icon-item-title">Reason #3</div>
        <div class="icon-item-copy">Discount on Merchandise</div>
      </li>
      <li class="icon-list-item">
        <div class="icon-wrap popcorn icon-replace">Popcorn</div>
        <div class="icon-item-title">Reason #4</div>
        <div class="icon-item-copy">Free Popcorn</div>
      </li>
      <li class="icon-list-item">
        <div class="icon-wrap adv-tickets icon-replace">Tickets</div>
        <div class="icon-item-title">Reason #5</div>
        <div class="icon-item-copy">Advanced Tickets to the Folk Festival</div>
      </li>
      <li class="icon-list-item">
        <div class="icon-wrap beer icon-replace">Beer</div>
        <div class="icon-item-title">Reason #6</div>
        <div class="icon-item-copy">Beer at the Shows</div>
      </li>
    </ul>';

  $export['membership_icon_list'] = $fe_block_boxes;

  return $export;
}
