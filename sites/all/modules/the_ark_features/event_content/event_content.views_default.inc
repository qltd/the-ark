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
  $export['sponsors'] = $view;

  return $export;
}
