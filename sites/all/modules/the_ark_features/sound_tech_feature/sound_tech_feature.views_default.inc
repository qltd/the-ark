<?php
/**
 * @file
 * sound_tech_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sound_tech_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sound_tech_accounts';
  $view->description = '';
  $view->tag = 'The Ark';
  $view->base_table = 'users';
  $view->human_name = 'Sound Tech Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view sound tech pages';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );

  /* Display: Sound Tech Users - Entity Reference */
  $handler = $view->new_display('entityreference', 'Sound Tech Users - Entity Reference', 'sound_tech_users_entity');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Sound Tech Users - Page */
  $handler = $view->new_display('page', 'Sound Tech Users - Page', 'sound_tech_users_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sound Tech Users';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_name_last' => 'field_name_last',
    'mail' => 'mail',
    'field_sound_tech_duty' => 'field_sound_tech_duty',
    'rid' => 'rid',
  );
  $handler->display->display_options['style_options']['default'] = 'field_name_last';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_name_last' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sound_tech_duty' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links">
  <li><a href="/admin/sound-tech/users/add">Add sound tech user</a></li>
</ul>
<div class="item-list">
  <ul>
    <li>Regular lead tech duty &mdash; 3 or more shows per month</li>
    <li>Reserve lead tech duty &mdash; 1 or fewer shows per month</li>
    <li>Retired &mdash; not active, but may be willing to do a show sometime</li>
    <li>Assistant tech duty &mdash; available as an assistant to a lead tech</li>
  </ul>
</div>
<h2>Names, Roles, and Contact Information</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_name_last']['id'] = 'field_name_last';
  $handler->display->display_options['fields']['field_name_last']['table'] = 'field_data_field_name_last';
  $handler->display->display_options['fields']['field_name_last']['field'] = 'field_name_last';
  $handler->display->display_options['fields']['field_name_last']['label'] = 'Name';
  $handler->display->display_options['fields']['field_name_last']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_name_last']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['field_name_last']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_last']['empty'] = '[name]';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid_1']['id'] = 'rid_1';
  $handler->display->display_options['fields']['rid_1']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid_1']['field'] = 'rid';
  $handler->display->display_options['fields']['rid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rid_1']['type'] = 'ul';
  /* Field: User: Sound Tech Duty */
  $handler->display->display_options['fields']['field_sound_tech_duty']['id'] = 'field_sound_tech_duty';
  $handler->display->display_options['fields']['field_sound_tech_duty']['table'] = 'field_data_field_sound_tech_duty';
  $handler->display->display_options['fields']['field_sound_tech_duty']['field'] = 'field_sound_tech_duty';
  $handler->display->display_options['fields']['field_sound_tech_duty']['label'] = 'Duty/Position';
  $handler->display->display_options['fields']['field_sound_tech_duty']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Home */
  $handler->display->display_options['fields']['field_phone_home']['id'] = 'field_phone_home';
  $handler->display->display_options['fields']['field_phone_home']['table'] = 'field_data_field_phone_home';
  $handler->display->display_options['fields']['field_phone_home']['field'] = 'field_phone_home';
  $handler->display->display_options['fields']['field_phone_home']['label'] = '';
  $handler->display->display_options['fields']['field_phone_home']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone_home']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_phone_home']['alter']['text'] = '<li><strong>Home</strong> [field_phone_home]</li>';
  $handler->display->display_options['fields']['field_phone_home']['element_label_colon'] = FALSE;
  /* Field: User: Mobile */
  $handler->display->display_options['fields']['field_phone_mobile']['id'] = 'field_phone_mobile';
  $handler->display->display_options['fields']['field_phone_mobile']['table'] = 'field_data_field_phone_mobile';
  $handler->display->display_options['fields']['field_phone_mobile']['field'] = 'field_phone_mobile';
  $handler->display->display_options['fields']['field_phone_mobile']['label'] = '';
  $handler->display->display_options['fields']['field_phone_mobile']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone_mobile']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_phone_mobile']['alter']['text'] = '<li><strong>Mobile</strong> [field_phone_mobile]</li>';
  $handler->display->display_options['fields']['field_phone_mobile']['element_label_colon'] = FALSE;
  /* Field: User: Work */
  $handler->display->display_options['fields']['field_phone_work']['id'] = 'field_phone_work';
  $handler->display->display_options['fields']['field_phone_work']['table'] = 'field_data_field_phone_work';
  $handler->display->display_options['fields']['field_phone_work']['field'] = 'field_phone_work';
  $handler->display->display_options['fields']['field_phone_work']['label'] = '';
  $handler->display->display_options['fields']['field_phone_work']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone_work']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_phone_work']['alter']['text'] = '<li><strong>Work</strong> [field_phone_work]</li>';
  $handler->display->display_options['fields']['field_phone_work']['element_label_colon'] = FALSE;
  /* Field: Phone Numbers */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Phone Numbers';
  $handler->display->display_options['fields']['nothing']['label'] = 'Phone';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>[field_phone_home][field_phone_mobile][field_phone_work]</ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Last Name (field_name_last) */
  $handler->display->display_options['sorts']['field_name_last_value']['id'] = 'field_name_last_value';
  $handler->display->display_options['sorts']['field_name_last_value']['table'] = 'field_data_field_name_last';
  $handler->display->display_options['sorts']['field_name_last_value']['field'] = 'field_name_last_value';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['path'] = 'admin/sound-tech/users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sound Tech Users';
  $handler->display->display_options['menu']['description'] = 'Sound Tech Users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['sound_tech_accounts'] = $view;

  return $export;
}
