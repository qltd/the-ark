<?php
/**
 * @file
 * event_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function event_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function event_content_image_default_styles() {
  $styles = array();

  // Exported image style: event_image.
  $styles['event_image'] = array(
    'name' => 'event_image',
    'label' => 'Event Image (580x365)',
    'effects' => array(
      15 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 580,
          'height' => 365,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_thumbnail.
  $styles['event_thumbnail'] = array(
    'name' => 'event_thumbnail',
    'label' => 'Event Thumbnail (160x135)',
    'effects' => array(
      16 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 135,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sponsor.
  $styles['sponsor'] = array(
    'name' => 'sponsor',
    'label' => 'Sponsor (height <= 75)',
    'effects' => array(
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 75,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function event_content_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A show or event that will have a distinct page, and representation on the calendar.'),
      'has_title' => '1',
      'title_label' => t('Artist or Event Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
