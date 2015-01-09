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
    'field_augmented_links' => array(
      'element_type' => 'div',
      'class' => 'augmented-links-item',
    ),
  );
  /* Field: Content: Augmented Links */
  $handler->display->display_options['fields']['field_augmented_links']['id'] = 'field_augmented_links';
  $handler->display->display_options['fields']['field_augmented_links']['table'] = 'field_data_field_augmented_links';
  $handler->display->display_options['fields']['field_augmented_links']['field'] = 'field_augmented_links';
  $handler->display->display_options['fields']['field_augmented_links']['label'] = '';
  $handler->display->display_options['fields']['field_augmented_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_augmented_links']['hide_empty'] = TRUE;
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
  $view->name = 'basic_page_columned_text';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Basic Page Columned Text';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'columned-text-view';
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
    'field_body_column' => array(
      'element_type' => 'div',
      'class' => 'columned-text-item',
    ),
  );
  /* Field: Content: Additional Content (optional) */
  $handler->display->display_options['fields']['field_body_column']['id'] = 'field_body_column';
  $handler->display->display_options['fields']['field_body_column']['table'] = 'field_data_field_body_column';
  $handler->display->display_options['fields']['field_body_column']['field'] = 'field_body_column';
  $handler->display->display_options['fields']['field_body_column']['label'] = '';
  $handler->display->display_options['fields']['field_body_column']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_body_column']['hide_empty'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Columned Text Block */
  $handler = $view->new_display('block', 'Columned Text Block', 'basic_page_columned_text');
  $export['basic_page_columned_text'] = $view;

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
  $handler->display->display_options['row_options']['skip_blank'] = 1;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_expandable_details' => array(
      'element_type' => 'div',
      'class' => 'expandable-details-item',
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[field_expandable_details_heading]';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Field: Content: Heading */
  $handler->display->display_options['fields']['field_expandable_details_heading']['id'] = 'field_expandable_details_heading';
  $handler->display->display_options['fields']['field_expandable_details_heading']['table'] = 'field_data_field_expandable_details_heading';
  $handler->display->display_options['fields']['field_expandable_details_heading']['field'] = 'field_expandable_details_heading';
  $handler->display->display_options['fields']['field_expandable_details_heading']['label'] = '';
  $handler->display->display_options['fields']['field_expandable_details_heading']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expandable_details_heading']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_expandable_details_heading']['alter']['text'] = '<h2>[field_expandable_details_heading]</h2>';
  $handler->display->display_options['fields']['field_expandable_details_heading']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expandable_details_heading']['hide_empty'] = TRUE;
  /* Field: Content: Expandable Details */
  $handler->display->display_options['fields']['field_expandable_details']['id'] = 'field_expandable_details';
  $handler->display->display_options['fields']['field_expandable_details']['table'] = 'field_data_field_expandable_details';
  $handler->display->display_options['fields']['field_expandable_details']['field'] = 'field_expandable_details';
  $handler->display->display_options['fields']['field_expandable_details']['label'] = '';
  $handler->display->display_options['fields']['field_expandable_details']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expandable_details']['hide_empty'] = TRUE;
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

  $view = new view();
  $view->name = 'quotes_display';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Quotes Display';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'view-quotes-display';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Quote Source */
  $handler->display->display_options['fields']['field_quote_source']['id'] = 'field_quote_source';
  $handler->display->display_options['fields']['field_quote_source']['table'] = 'field_data_field_quote_source';
  $handler->display->display_options['fields']['field_quote_source']['field'] = 'field_quote_source';
  $handler->display->display_options['fields']['field_quote_source']['label'] = '';
  $handler->display->display_options['fields']['field_quote_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_quote_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quote_source']['type'] = 'text_plain';
  /* Field: Content: Quote */
  $handler->display->display_options['fields']['field_quote']['id'] = 'field_quote';
  $handler->display->display_options['fields']['field_quote']['table'] = 'field_data_field_quote';
  $handler->display->display_options['fields']['field_quote']['field'] = 'field_quote';
  $handler->display->display_options['fields']['field_quote']['label'] = '';
  $handler->display->display_options['fields']['field_quote']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_quote']['alter']['text'] = '<div class="quote-wrap">
<div class="quote-body">
<p class="quote-paragraph">[field_quote]</p>
</div>
<div class="quote-source">[field_quote_source]</div>
</div>';
  $handler->display->display_options['fields']['field_quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quote']['type'] = 'text_plain';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );

  /* Display: Quotes Display */
  $handler = $view->new_display('block', 'Quotes Display', 'block');
  $export['quotes_display'] = $view;

  $view = new view();
  $view->name = 'tabs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'tabs-view';
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
    'field_tabs' => array(
      'element_type' => 'div',
      'class' => 'tabs-item',
    ),
  );
  /* Field: Content: Tabs */
  $handler->display->display_options['fields']['field_tabs']['id'] = 'field_tabs';
  $handler->display->display_options['fields']['field_tabs']['table'] = 'field_data_field_tabs';
  $handler->display->display_options['fields']['field_tabs']['field'] = 'field_tabs';
  $handler->display->display_options['fields']['field_tabs']['label'] = '';
  $handler->display->display_options['fields']['field_tabs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tabs']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tabs']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_tabs']['settings'] = array(
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_tabs']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_tabs']['delta_offset'] = '0';
  /* Sort criterion: Content: Tabs (field_tabs:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_tabs';
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

  /* Display: Tabs */
  $handler = $view->new_display('block', 'Tabs', 'tabs');
  $handler->display->display_options['block_description'] = 'Tabs';

  /* Display: Toggles */
  $handler = $view->new_display('block', 'Toggles', 'tab_toggles');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'tab-toggles-view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_tabs' => array(
      'element_type' => 'div',
      'class' => 'tab-toggles-item',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Homepage Toggles */
  $handler = $view->new_display('block', 'Homepage Toggles', 'homepage_tab_toggles');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'tab-toggles-view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_tabs' => array(
      'element_type' => 'div',
      'class' => 'tab-toggles-item',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a class="tab-toggle" href="#" role="button" data-tab-toggle-id="[counter]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tab' => 'tab',
  );

  /* Display: Homepage Tabs */
  $handler = $view->new_display('block', 'Homepage Tabs', 'homepage_tabs');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'tabs-view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_tabs' => array(
      'element_type' => 'div',
      'class' => 'tab-toggles-item',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a class="tab-toggle" href="#" role="button" data-tab-toggle-id="[counter]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_tab_media']['id'] = 'field_tab_media';
  $handler->display->display_options['fields']['field_tab_media']['table'] = 'field_data_field_tab_media';
  $handler->display->display_options['fields']['field_tab_media']['field'] = 'field_tab_media';
  $handler->display->display_options['fields']['field_tab_media']['label'] = '';
  $handler->display->display_options['fields']['field_tab_media']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tab_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tab_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tab_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_tab_media']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Primary Link */
  $handler->display->display_options['fields']['field_primary_link']['id'] = 'field_primary_link';
  $handler->display->display_options['fields']['field_primary_link']['table'] = 'field_data_field_primary_link';
  $handler->display->display_options['fields']['field_primary_link']['field'] = 'field_primary_link';
  $handler->display->display_options['fields']['field_primary_link']['label'] = '';
  $handler->display->display_options['fields']['field_primary_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_primary_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_primary_link']['click_sort_column'] = 'url';
  /* Field: Content: Related Links */
  $handler->display->display_options['fields']['field_related_links']['id'] = 'field_related_links';
  $handler->display->display_options['fields']['field_related_links']['table'] = 'field_data_field_related_links';
  $handler->display->display_options['fields']['field_related_links']['field'] = 'field_related_links';
  $handler->display->display_options['fields']['field_related_links']['label'] = '';
  $handler->display->display_options['fields']['field_related_links']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_links']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_related_links']['alter']['text'] = '<span class="tab-content-body-link-span">[field_related_links]</span>';
  $handler->display->display_options['fields']['field_related_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_related_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_links']['separator'] = ' ';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="tab-container" data-tab-id="[counter]">
  <h2 class="tab-title expander">[title]</h2>
  <div class="tab-content expander-content">
    <div class="tab-content-body">
      <div class="tab-content-body-media">
        [field_tab_media]
      </div>
      <div class="tab-content-body-text">
        [body]
      </div>
      <div class="tab-content-body-primary-link">
        [field_primary_link]
      </div>
      <div class="tab-content-body-links">
        [field_related_links]
      </div>
    </div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tab' => 'tab',
  );
  $export['tabs'] = $view;

  return $export;
}
