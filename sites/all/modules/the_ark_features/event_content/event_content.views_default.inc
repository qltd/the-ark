<?php
/**
 * @file
 * event_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function event_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Events Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View Calendar';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Links';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="event-cal-links"><a href="/download-calendar"><i class="fa fa-download"></i> Download Calendar</a></div>';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'calendar-image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'event_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Event Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Event Link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="event-link" href="[path]">View Event</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Spotify URI */
  $handler->display->display_options['fields']['field_spotify_uri']['id'] = 'field_spotify_uri';
  $handler->display->display_options['fields']['field_spotify_uri']['table'] = 'field_data_field_spotify_uri';
  $handler->display->display_options['fields']['field_spotify_uri']['field'] = 'field_spotify_uri';
  $handler->display->display_options['fields']['field_spotify_uri']['label'] = '';
  $handler->display->display_options['fields']['field_spotify_uri']['element_label_colon'] = FALSE;
  /* Field: Content: Ticket URL(s) */
  $handler->display->display_options['fields']['field_ticket_url']['id'] = 'field_ticket_url';
  $handler->display->display_options['fields']['field_ticket_url']['table'] = 'field_data_field_ticket_url';
  $handler->display->display_options['fields']['field_ticket_url']['field'] = 'field_ticket_url';
  $handler->display->display_options['fields']['field_ticket_url']['label'] = '';
  $handler->display->display_options['fields']['field_ticket_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ticket_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_ticket_url']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ticket_url']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Co-headlining Act(s) */
  $handler->display->display_options['fields']['field_coheadlining_act']['id'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['table'] = 'field_data_field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['field'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['label'] = '';
  $handler->display->display_options['fields']['field_coheadlining_act']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['text'] = ' <span class="delimiter">//</span> <a href="[path]">[field_coheadlining_act]</a>';
  $handler->display->display_options['fields']['field_coheadlining_act']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coheadlining_act']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_coheadlining_act']['separator'] = '';
  /* Field: Title Display */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Title Display';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title][field_coheadlining_act]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'calendar-title-display';
  /* Field: Content: Special Guest(s) */
  $handler->display->display_options['fields']['field_special_guest']['id'] = 'field_special_guest';
  $handler->display->display_options['fields']['field_special_guest']['table'] = 'field_data_field_special_guest';
  $handler->display->display_options['fields']['field_special_guest']['field'] = 'field_special_guest';
  $handler->display->display_options['fields']['field_special_guest']['label'] = 'Special Guest';
  $handler->display->display_options['fields']['field_special_guest']['element_wrapper_class'] = 'calendar-guest-opener';
  $handler->display->display_options['fields']['field_special_guest']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_special_guest']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_special_guest']['separator'] = ' <span class="delimiter">//</span> ';
  /* Field: Content: Opening Act(s) */
  $handler->display->display_options['fields']['field_opener']['id'] = 'field_opener';
  $handler->display->display_options['fields']['field_opener']['table'] = 'field_data_field_opener';
  $handler->display->display_options['fields']['field_opener']['field'] = 'field_opener';
  $handler->display->display_options['fields']['field_opener']['label'] = 'Opener';
  $handler->display->display_options['fields']['field_opener']['element_wrapper_class'] = 'calendar-guest-opener';
  $handler->display->display_options['fields']['field_opener']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opener']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_opener']['separator'] = ' <span class="delimiter">//</span> ';
  /* Field: Content: Venue */
  $handler->display->display_options['fields']['field_venue']['id'] = 'field_venue';
  $handler->display->display_options['fields']['field_venue']['table'] = 'field_data_field_venue';
  $handler->display->display_options['fields']['field_venue']['field'] = 'field_venue';
  $handler->display->display_options['fields']['field_venue']['label'] = '';
  $handler->display->display_options['fields']['field_venue']['element_class'] = 'calendar-venue';
  $handler->display->display_options['fields']['field_venue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_venue']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Load-in Time */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Ticket Price Display */
  $handler->display->display_options['fields']['field_price_display']['id'] = 'field_price_display';
  $handler->display->display_options['fields']['field_price_display']['table'] = 'field_data_field_price_display';
  $handler->display->display_options['fields']['field_price_display']['field'] = 'field_price_display';
  $handler->display->display_options['fields']['field_price_display']['label'] = '';
  $handler->display->display_options['fields']['field_price_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_price_display']['alter']['text'] = ', [field_price_display]';
  $handler->display->display_options['fields']['field_price_display']['element_label_colon'] = FALSE;
  /* Field: Time and Ticket Price */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Time and Ticket Price';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_date][field_price_display]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_class'] = 'calendar-time-price';
  /* Sort criterion: Content: Load-in Time (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Genre(s) (field_genre) */
  $handler->display->display_options['filters']['field_genre_tid']['id'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['table'] = 'field_data_field_genre';
  $handler->display->display_options['filters']['field_genre_tid']['field'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_genre_tid']['expose']['operator_id'] = 'field_genre_tid_op';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['label'] = 'Filter by:';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['operator'] = 'field_genre_tid_op';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['identifier'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_genre_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_genre_tid']['vocabulary'] = 'genre';

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'events_calendar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Shows & Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Genre(s) (field_genre) */
  $handler->display->display_options['filters']['field_genre_tid']['id'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['table'] = 'field_data_field_genre';
  $handler->display->display_options['filters']['field_genre_tid']['field'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_genre_tid']['expose']['operator_id'] = 'field_genre_tid_op';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['label'] = 'Filter by:';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['operator'] = 'field_genre_tid_op';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['identifier'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_genre_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_genre_tid']['vocabulary'] = 'genre';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sound_tech' => 'sound_tech',
  );
  $handler->display->display_options['path'] = 'shows-events/calendar';
  $handler->display->display_options['menu']['title'] = 'Calendar';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-date/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-date/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Load-in Time */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_date']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-date/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'events_upcoming');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'events-upcoming-view';
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'calendar-column';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_image' => array(
      'element_type' => 'div',
      'class' => 'calendar-image',
    ),
    'nothing' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_spotify_uri' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ticket_url' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'nothing_1' => array(
      'element_type' => 'div',
      'class' => 'calendar-title-display',
    ),
    'field_special_guest' => array(
      'element_type' => 'div',
      'class' => 'calendar-guest-opener',
      'label_element_type' => 'span',
      'label_class' => '',
    ),
    'field_opener' => array(
      'element_type' => 'div',
      'class' => 'calendar-guest-opener',
      'label_element_type' => 'span',
      'label_class' => '',
    ),
    'field_venue' => array(
      'element_type' => 'div',
      'class' => 'calendar-venue',
    ),
    'field_date_doors' => array(
      'element_type' => 'div',
      'class' => 'calendar-day-month',
    ),
    'nothing_2' => array(
      'element_type' => 'div',
      'class' => 'calendar-time-price',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="events-upcoming-title">Upcoming Shows</h2>
<a class="events-upcoming-view-calendar-link" href="/shows-events/calendar">View Full Calendar</a>';
  $handler->display->display_options['header']['area']['format'] = 'admin_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'calendar-image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'event_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Event Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Event Link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="event-link" href="[path]">View Event</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Spotify URI */
  $handler->display->display_options['fields']['field_spotify_uri']['id'] = 'field_spotify_uri';
  $handler->display->display_options['fields']['field_spotify_uri']['table'] = 'field_data_field_spotify_uri';
  $handler->display->display_options['fields']['field_spotify_uri']['field'] = 'field_spotify_uri';
  $handler->display->display_options['fields']['field_spotify_uri']['label'] = '';
  $handler->display->display_options['fields']['field_spotify_uri']['element_label_colon'] = FALSE;
  /* Field: Content: Ticket URL(s) */
  $handler->display->display_options['fields']['field_ticket_url']['id'] = 'field_ticket_url';
  $handler->display->display_options['fields']['field_ticket_url']['table'] = 'field_data_field_ticket_url';
  $handler->display->display_options['fields']['field_ticket_url']['field'] = 'field_ticket_url';
  $handler->display->display_options['fields']['field_ticket_url']['label'] = '';
  $handler->display->display_options['fields']['field_ticket_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ticket_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_ticket_url']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ticket_url']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Co-headlining Act(s) */
  $handler->display->display_options['fields']['field_coheadlining_act']['id'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['table'] = 'field_data_field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['field'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['label'] = '';
  $handler->display->display_options['fields']['field_coheadlining_act']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['text'] = ' <span class="delimiter">//</span> <a href="[path]">[field_coheadlining_act]</a>';
  $handler->display->display_options['fields']['field_coheadlining_act']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coheadlining_act']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_coheadlining_act']['separator'] = '';
  /* Field: Title Display */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Title Display';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title][field_coheadlining_act]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'calendar-title-display';
  /* Field: Content: Special Guest(s) */
  $handler->display->display_options['fields']['field_special_guest']['id'] = 'field_special_guest';
  $handler->display->display_options['fields']['field_special_guest']['table'] = 'field_data_field_special_guest';
  $handler->display->display_options['fields']['field_special_guest']['field'] = 'field_special_guest';
  $handler->display->display_options['fields']['field_special_guest']['label'] = 'Special Guest';
  $handler->display->display_options['fields']['field_special_guest']['element_wrapper_class'] = 'calendar-guest-opener';
  $handler->display->display_options['fields']['field_special_guest']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_special_guest']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_special_guest']['separator'] = ' <span class="delimiter">//</span> ';
  /* Field: Content: Opening Act(s) */
  $handler->display->display_options['fields']['field_opener']['id'] = 'field_opener';
  $handler->display->display_options['fields']['field_opener']['table'] = 'field_data_field_opener';
  $handler->display->display_options['fields']['field_opener']['field'] = 'field_opener';
  $handler->display->display_options['fields']['field_opener']['label'] = 'Opener';
  $handler->display->display_options['fields']['field_opener']['element_wrapper_class'] = 'calendar-guest-opener';
  $handler->display->display_options['fields']['field_opener']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opener']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_opener']['separator'] = ' <span class="delimiter">//</span> ';
  /* Field: Content: Venue */
  $handler->display->display_options['fields']['field_venue']['id'] = 'field_venue';
  $handler->display->display_options['fields']['field_venue']['table'] = 'field_data_field_venue';
  $handler->display->display_options['fields']['field_venue']['field'] = 'field_venue';
  $handler->display->display_options['fields']['field_venue']['label'] = '';
  $handler->display->display_options['fields']['field_venue']['element_class'] = 'calendar-venue';
  $handler->display->display_options['fields']['field_venue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_venue']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Load-in Time */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Ticket Price Display */
  $handler->display->display_options['fields']['field_price_display']['id'] = 'field_price_display';
  $handler->display->display_options['fields']['field_price_display']['table'] = 'field_data_field_price_display';
  $handler->display->display_options['fields']['field_price_display']['field'] = 'field_price_display';
  $handler->display->display_options['fields']['field_price_display']['label'] = '';
  $handler->display->display_options['fields']['field_price_display']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price_display']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_price_display']['alter']['text'] = ', [field_price_display]';
  $handler->display->display_options['fields']['field_price_display']['element_label_colon'] = FALSE;
  /* Field: Content: Doors (Date and Time) */
  $handler->display->display_options['fields']['field_date_doors']['id'] = 'field_date_doors';
  $handler->display->display_options['fields']['field_date_doors']['table'] = 'field_data_field_date_doors';
  $handler->display->display_options['fields']['field_date_doors']['field'] = 'field_date_doors';
  $handler->display->display_options['fields']['field_date_doors']['label'] = '';
  $handler->display->display_options['fields']['field_date_doors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_doors']['settings'] = array(
    'format_type' => 'date_with_abbreviated_day_and_month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Time and Ticket Price */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Time and Ticket Price';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_date][field_price_display]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_class'] = 'calendar-time-price';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sound_tech' => 'sound_tech',
  );
  $export['events_calendar'] = $view;

  $view = new view();
  $view->name = 'sponsors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Sponsors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_footer' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Taxonomy term: Featured Sponsor (field_featured) */
  $handler->display->display_options['filters']['field_featured_value']['id'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['table'] = 'field_data_field_featured';
  $handler->display->display_options['filters']['field_featured_value']['field'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['value'] = array(
    1 => '1',
  );

  /* Display: Sponsors Featured - Block */
  $handler = $view->new_display('block', 'Sponsors Featured - Block', 'sponsors_featured_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Sponsor';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'sponsors-featured';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_image_footer' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Link */
  $handler->display->display_options['fields']['field_link_sponsor']['id'] = 'field_link_sponsor';
  $handler->display->display_options['fields']['field_link_sponsor']['table'] = 'field_data_field_link_sponsor';
  $handler->display->display_options['fields']['field_link_sponsor']['field'] = 'field_link_sponsor';
  $handler->display->display_options['fields']['field_link_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_link_sponsor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_sponsor']['click_sort_column'] = 'url';
  /* Field: Taxonomy term: Footer Image */
  $handler->display->display_options['fields']['field_image_footer']['id'] = 'field_image_footer';
  $handler->display->display_options['fields']['field_image_footer']['table'] = 'field_data_field_image_footer';
  $handler->display->display_options['fields']['field_image_footer']['field'] = 'field_image_footer';
  $handler->display->display_options['fields']['field_image_footer']['label'] = '';
  $handler->display->display_options['fields']['field_image_footer']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image_footer']['alter']['path'] = '[field_link_sponsor]';
  $handler->display->display_options['fields']['field_image_footer']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_image_footer']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_image_footer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_footer']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_footer']['settings'] = array(
    'image_style' => 'sponsor',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';

  /* Display: Corporate Sponsors - Block */
  $handler = $view->new_display('block', 'Corporate Sponsors - Block', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'block-corporate-sponsors';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['list']['element_type'] = 'ul';
  $handler->display->display_options['style_options']['list']['class'] = 'corporate-sponsors-list';
  $handler->display->display_options['style_options']['row']['element_type'] = 'li';
  $handler->display->display_options['style_options']['row']['class'] = 'corporate-sponsors-item';
  $handler->display->display_options['style_options']['row']['last_every_nth'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'name' => array(
      'element_type' => 'div',
      'class' => 'sponsor-name',
    ),
    'field_image' => array(
      'element_type' => 'div',
      'class' => 'sponsor-logo-wrap',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Link */
  $handler->display->display_options['fields']['field_link_sponsor']['id'] = 'field_link_sponsor';
  $handler->display->display_options['fields']['field_link_sponsor']['table'] = 'field_data_field_link_sponsor';
  $handler->display->display_options['fields']['field_link_sponsor']['field'] = 'field_link_sponsor';
  $handler->display->display_options['fields']['field_link_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_link_sponsor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_sponsor']['click_sort_column'] = 'url';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '[field_link_sponsor]';
  $handler->display->display_options['fields']['field_image']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'sponsor',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sponsor' => 'sponsor',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Corporate Sponsor (field_corporate) */
  $handler->display->display_options['filters']['field_corporate_value']['id'] = 'field_corporate_value';
  $handler->display->display_options['filters']['field_corporate_value']['table'] = 'field_data_field_corporate';
  $handler->display->display_options['filters']['field_corporate_value']['field'] = 'field_corporate_value';
  $handler->display->display_options['filters']['field_corporate_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_corporate_value']['group'] = 1;
  $export['sponsors'] = $view;

  return $export;
}
