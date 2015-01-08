<?php
/**
 * @file
 * basic_page_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function basic_page_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function basic_page_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function basic_page_content_image_default_styles() {
  $styles = array();

  // Exported image style: link_thumbnail.
  $styles['link_thumbnail'] = array(
    'name' => 'link_thumbnail',
    'label' => 'Link Thumbnail (280x185)',
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
          'width' => 280,
          'height' => 185,
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
function basic_page_content_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'quote' => array(
      'name' => t('Quote'),
      'base' => 'node_content',
      'description' => t('Use this content type to add quotes to The Ark site. Currently displayed on the About page.'),
      'has_title' => '1',
      'title_label' => t('Quote Name'),
      'help' => t('The Quote Name is used for content management purposes only. It will not be shown to the user.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
