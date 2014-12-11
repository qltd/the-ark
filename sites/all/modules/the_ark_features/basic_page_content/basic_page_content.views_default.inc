<?php
/**
 * @file
 * basic_page_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function basic_page_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'augmented_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Augmented Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'augmented-links-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Field: Content: Augmented Links */
  $handler->display->display_options['fields']['field_augmented_links']['id'] = 'field_augmented_links';
  $handler->display->display_options['fields']['field_augmented_links']['table'] = 'field_data_field_augmented_links';
  $handler->display->display_options['fields']['field_augmented_links']['field'] = 'field_augmented_links';
  $handler->display->display_options['fields']['field_augmented_links']['label'] = '';
  $handler->display->display_options['fields']['field_augmented_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_augmented_links']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_augmented_links']['settings'] = array(
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_augmented_links']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_augmented_links']['delta_offset'] = '0';
  /* Sort criterion: Content: Augmented Links (field_augmented_links:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_augmented_links';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Augmented Links */
  $handler = $view->new_display('block', 'Augmented Links', 'augmented_links');
  $export['augmented_links'] = $view;

  $view = new view();
  $view->name = 'expandable_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Expandable Details';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'expandable-details-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_expandable_details' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Field: Content: Expandable Details */
  $handler->display->display_options['fields']['field_expandable_details']['id'] = 'field_expandable_details';
  $handler->display->display_options['fields']['field_expandable_details']['table'] = 'field_data_field_expandable_details';
  $handler->display->display_options['fields']['field_expandable_details']['field'] = 'field_expandable_details';
  $handler->display->display_options['fields']['field_expandable_details']['label'] = '';
  $handler->display->display_options['fields']['field_expandable_details']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expandable_details']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_expandable_details']['settings'] = array(
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_expandable_details']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_expandable_details']['delta_offset'] = '0';
  /* Sort criterion: Content: Expandable Details (field_expandable_details:delta) */
  $handler->display->display_options['sorts']['delta_1']['id'] = 'delta_1';
  $handler->display->display_options['sorts']['delta_1']['table'] = 'field_data_field_expandable_details';
  $handler->display->display_options['sorts']['delta_1']['field'] = 'delta';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Expandable Details */
  $handler = $view->new_display('block', 'Expandable Details', 'expandable_details');
  $export['expandable_details'] = $view;

  return $export;
}
