<?php
/**
 * @file
 * header_region.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function header_region_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function header_region_image_default_styles() {
  $styles = array();

  // Exported image style: header_image_desktop.
  $styles['header_image_desktop'] = array(
    'name' => 'header_image_desktop',
    'label' => 'Header Image Desktop (1340x170)',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1340,
          'height' => 170,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: header_image_mobile.
  $styles['header_image_mobile'] = array(
    'name' => 'header_image_mobile',
    'label' => 'Header Image Mobile (480x170)',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 170,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: header_image_mobile_wide.
  $styles['header_image_mobile_wide'] = array(
    'name' => 'header_image_mobile_wide',
    'label' => 'Header Image Mobile Wide (767x170)',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 767,
          'height' => 170,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: header_image_tablet.
  $styles['header_image_tablet'] = array(
    'name' => 'header_image_tablet',
    'label' => 'Header Image Tablet (1024x170)',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1024,
          'height' => 170,
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
function header_region_node_info() {
  $items = array(
    'header_image' => array(
      'name' => t('Header Image'),
      'base' => 'node_content',
      'description' => t('Images that are displayed in the header on interior pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
