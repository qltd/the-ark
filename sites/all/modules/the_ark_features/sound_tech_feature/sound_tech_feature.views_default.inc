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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Sound Tech Duty */
  $handler->display->display_options['fields']['field_sound_tech_duty']['id'] = 'field_sound_tech_duty';
  $handler->display->display_options['fields']['field_sound_tech_duty']['table'] = 'field_data_field_sound_tech_duty';
  $handler->display->display_options['fields']['field_sound_tech_duty']['field'] = 'field_sound_tech_duty';
  $handler->display->display_options['fields']['field_sound_tech_duty']['label'] = '';
  $handler->display->display_options['fields']['field_sound_tech_duty']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sound_tech_duty']['alter']['text'] = '<strong>[field_sound_tech_duty]</strong>';
  $handler->display->display_options['fields']['field_sound_tech_duty']['element_label_colon'] = FALSE;

  /* Display: Sound Tech Users - Page */
  $handler = $view->new_display('page', 'Sound Tech Users - Page', 'sound_tech_users_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sound Tech Users';
  $handler->display->display_options['enabled'] = FALSE;
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

  /* Display: Sound Tech Users - Block */
  $handler = $view->new_display('block', 'Sound Tech Users - Block', 'sound_tech_users_block');
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
    'uid' => 'uid',
    'edit_node' => 'edit_node',
    'name' => 'name',
    'field_name_last' => 'field_name_last',
    'rid' => 'rid',
    'field_sound_tech_duty' => 'field_sound_tech_duty',
    'mail' => 'mail',
    'field_phone_home' => 'field_phone_home',
    'field_phone_mobile' => 'field_phone_mobile',
    'field_phone_work' => 'field_phone_work',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'field_name_last';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
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
    'rid' => array(
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
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone_home' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone_mobile' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone_work' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
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
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/admin/sound-tech/people/add">Add sound tech user</a></li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
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
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rid']['type'] = 'ul';
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
  /* Filter criterion: User: Sound Tech Duty (field_sound_tech_duty) */
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['id'] = 'field_sound_tech_duty_value';
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['table'] = 'field_data_field_sound_tech_duty';
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['field'] = 'field_sound_tech_duty_value';
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['expose']['operator_id'] = 'field_sound_tech_duty_value_op';
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['expose']['label'] = 'Duty/Position';
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['expose']['operator'] = 'field_sound_tech_duty_value_op';
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['expose']['identifier'] = 'field_sound_tech_duty_value';
  $handler->display->display_options['filters']['field_sound_tech_duty_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $export['sound_tech_accounts'] = $view;

  $view = new view();
  $view->name = 'sound_tech_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sound Tech Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'sound-tech-events-block';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date_1' => 'field_date_1',
    'title' => 'title',
    'field_sound_tech' => 'field_sound_tech',
    'body' => 'body',
    'field_date' => 'field_date',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date_1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sound_tech' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_event_node']['id'] = 'reverse_field_event_node';
  $handler->display->display_options['relationships']['reverse_field_event_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_event_node']['field'] = 'reverse_field_event_node';
  $handler->display->display_options['relationships']['reverse_field_event_node']['label'] = 'Sound Tech Event';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Load-in Time */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Co-headlining Act(s) */
  $handler->display->display_options['fields']['field_coheadlining_act']['id'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['table'] = 'field_data_field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['field'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['label'] = '';
  $handler->display->display_options['fields']['field_coheadlining_act']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['text'] = ' // [field_coheadlining_act]';
  $handler->display->display_options['fields']['field_coheadlining_act']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coheadlining_act']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_coheadlining_act']['separator'] = ' // ';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Event/Show';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title][field_coheadlining_act]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Load-in Time */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Sound Tech(s) */
  $handler->display->display_options['fields']['field_sound_tech']['id'] = 'field_sound_tech';
  $handler->display->display_options['fields']['field_sound_tech']['table'] = 'field_data_field_sound_tech';
  $handler->display->display_options['fields']['field_sound_tech']['field'] = 'field_sound_tech';
  $handler->display->display_options['fields']['field_sound_tech']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['field_sound_tech']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sound_tech']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sound_tech']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sound_tech']['multi_type'] = 'ul';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['body']['label'] = 'Notes';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Stage Plot(s) */
  $handler->display->display_options['fields']['field_stage_plot']['id'] = 'field_stage_plot';
  $handler->display->display_options['fields']['field_stage_plot']['table'] = 'field_data_field_stage_plot';
  $handler->display->display_options['fields']['field_stage_plot']['field'] = 'field_stage_plot';
  $handler->display->display_options['fields']['field_stage_plot']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['field_stage_plot']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stage_plot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stage_plot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stage_plot']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_stage_plot']['settings'] = array(
    'text' => 'View',
  );
  $handler->display->display_options['fields']['field_stage_plot']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stage_plot']['multi_type'] = 'ul';
  /* Sort criterion: Content: Load-in Time (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
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
    'event' => 'event',
  );
  /* Filter criterion: Event Date and Time */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['ui_name'] = 'Event Date and Time';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now -4 hours';

  /* Display: Sound Tech Events - Block */
  $handler = $view->new_display('block', 'Sound Tech Events - Block', 'sound_tech_events_block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/admin/sound-tech/events/archive">Sound Tech Events Archive</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Load-in Time */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'abv_day_name_and_short_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Co-headlining Act(s) */
  $handler->display->display_options['fields']['field_coheadlining_act']['id'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['table'] = 'field_data_field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['field'] = 'field_coheadlining_act';
  $handler->display->display_options['fields']['field_coheadlining_act']['label'] = '';
  $handler->display->display_options['fields']['field_coheadlining_act']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_coheadlining_act']['alter']['text'] = ' // [field_coheadlining_act]';
  $handler->display->display_options['fields']['field_coheadlining_act']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coheadlining_act']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_coheadlining_act']['separator'] = ' // ';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Event/Show';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title][field_coheadlining_act]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Load-in Time */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Sound Tech(s) */
  $handler->display->display_options['fields']['field_sound_tech']['id'] = 'field_sound_tech';
  $handler->display->display_options['fields']['field_sound_tech']['table'] = 'field_data_field_sound_tech';
  $handler->display->display_options['fields']['field_sound_tech']['field'] = 'field_sound_tech';
  $handler->display->display_options['fields']['field_sound_tech']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['field_sound_tech']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sound_tech']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sound_tech']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sound_tech']['multi_type'] = 'ul';
  /* Field: Content: Sound Tech Information */
  $handler->display->display_options['fields']['field_sound_tech_information']['id'] = 'field_sound_tech_information';
  $handler->display->display_options['fields']['field_sound_tech_information']['table'] = 'field_data_field_sound_tech_information';
  $handler->display->display_options['fields']['field_sound_tech_information']['field'] = 'field_sound_tech_information';
  $handler->display->display_options['fields']['field_sound_tech_information']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['field_sound_tech_information']['label'] = 'Sound Tech';
  $handler->display->display_options['fields']['field_sound_tech_information']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['body']['label'] = 'Notes';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Stage Plot(s) */
  $handler->display->display_options['fields']['field_stage_plot']['id'] = 'field_stage_plot';
  $handler->display->display_options['fields']['field_stage_plot']['table'] = 'field_data_field_stage_plot';
  $handler->display->display_options['fields']['field_stage_plot']['field'] = 'field_stage_plot';
  $handler->display->display_options['fields']['field_stage_plot']['relationship'] = 'reverse_field_event_node';
  $handler->display->display_options['fields']['field_stage_plot']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stage_plot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stage_plot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_stage_plot']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_stage_plot']['settings'] = array(
    'text' => 'View',
  );
  $handler->display->display_options['fields']['field_stage_plot']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stage_plot']['multi_type'] = 'ul';

  /* Display: Sound Tech Events Archive - Block */
  $handler = $view->new_display('block', 'Sound Tech Events Archive - Block', 'sound_tech_events_archive_block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Load-in Time (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_value']['expose']['operator_id'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['label'] = 'Month and Year';
  $handler->display->display_options['filters']['field_date_value']['expose']['description'] = 'Use these fields to view sound tech events for a specific month and year.';
  $handler->display->display_options['filters']['field_date_value']['expose']['operator'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['identifier'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_value']['granularity'] = 'month';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-10:+1';
  $export['sound_tech_events'] = $view;

  return $export;
}
