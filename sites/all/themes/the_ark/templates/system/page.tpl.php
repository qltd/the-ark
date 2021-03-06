<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar']: Items for the sidebar.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see omega_preprocess_page()
 */
?>
<div class="l-page">
  <header class="l-header" role="banner">
    <div class="l-regionset--header">
      <?php if ($site_name): ?>
        <h1 class="site-name header-site-name">
          <a class="site-name-link" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
        </h1>
      <?php endif; ?>
      <div class="l-regionwrapper--header headroom--top no-js">
        <?php print render($page['header']); ?>
      </div>
      <?php print render($page['hero']); ?>
    </div>
  </header>

  <div class="l-main">
    <div class="l-content" role="main">
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="content-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php
        if (drupal_is_front_page()) {
            print render($page['under_hero']);
        }
      ?>
      <?php print render($page['content']); ?>
      <?php // print $feed_icons; ?>
       
        <?php if ($node->type === 'page'): //3573 ?>
            <div class="event-social">
                <a href="https://www.facebook.com/sharer/sharer.php?u=<?php print $GLOBALS['base_url'] . '/' . request_path(); ?>" role="button" target="_blank" rel="noopener noreferrer" data-network="facebook" class="event-social-button button-social facebook-share">Share</a>
                <a class="event-social-button button-social twitter-tweet"
                href="https://twitter.com/share?url=<?php print $GLOBALS['base_url'] . '/' . request_path(); ?>"
                role="button" target="_blank" rel="noopener noreferrer">Tweet</a>
            </div>
        <?php endif; ?>
    
    
    </div>


    <?php print render($page['sidebar']); ?>
  </div>

  <footer class="l-footer" role="contentinfo">
    <div class="l-regionset--footer">
      <!-- Begin Constant Contact Inline Form Code -->
      <div class="ctct-inline-form" data-form-id="752b5d0b-7e49-473a-956c-b078adb46da8"></div>
      <!-- End Constant Contact Inline Form Code -->
      <?php print render($page['footer']); ?>
      <div class="l-static--footer footer-block">
        <p class="footer-copyright footer-paragraph">Copyright <?php echo date("Y") ?>. All Rights Reserved.</p>
        <p class="footer-development footer-paragraph">Site Design + Development <a href="http://qltd.com" class="q-ltd" target="_blank" rel="noopener noreferrer">Q LTD</a></p>
      </div>
    </div>
  </footer>
  <!--[if lte IE 8]>
    <p class="browsehappy">You are using an <strong>outdated</strong> browser. Please <a href="http://browsehappy.com/">upgrade your browser</a> to view this site.</p>
  <![endif]-->
</div>
